package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
	"os/exec"
	"strings"
)

type Shell struct {
	users        string
	SocketServer *net.TCPListener
	socket       net.Conn
	reader       *bufio.Reader
	writer       *bufio.Writer
}

func InitShell(socketServer *net.TCPListener, socket *net.Conn) Shell {
	return Shell{users: "/etc/shell/users.bd",
		SocketServer: socketServer,
		socket:       *socket,
		reader:       bufio.NewReader(*socket),
		writer:       bufio.NewWriter(*socket)}
}

func (s *Shell) logIn() bool {
	// Consulta la base de datos de usuarios
	archivo, _ := os.ReadFile(s.users) // Lee el archivo y lo guarda en la variable
	strArchivo := string(archivo)      // castea la variable a string

	// Agrupa todo la informacion de los usuarios en un arreglo para su posterior consulta
	paramLogin := strings.Split(strArchivo, "\n") // Divide el string por cada salto de linea y lo guarda en un arreglo

	var newparamLogin []string
	for i := 0; i < len(paramLogin)-1; i++ {
		new := strings.Split(paramLogin[i], ":") // divide el arreglo anterior en un array con cada elemento que este separado con ":"
		newparamLogin = append(newparamLogin, new...)
	}

	// Recibe las credenciales por el socket
	msg := s.reader
	credentials, _ := msg.ReadString('\n')
	credentials = strings.TrimRight(credentials, "\r\n")
	// fmt.Println(credentials)
	credentialsFormated := strings.Split(credentials, ":")

	// Consulta la base de datos de usuarios
	for j := 0; j < len(newparamLogin); j += 2 {
		if newparamLogin[j] == credentialsFormated[0] && newparamLogin[j+1] == credentialsFormated[1] {
			s.writer.WriteString("1\n")
			s.writer.Flush()
			return true
		}
	}
	s.writer.WriteString("0\n")
	s.writer.Flush()
	return false
}

func (s *Shell) getEstado() string {
	// ----- memoria ------
	inf_mem := exec.Command("free", "-m")
	res_mem, _ := inf_mem.Output()
	inf_mem_array := strings.Fields(string(res_mem))
	mem := inf_mem_array[6] + inf_mem_array[8] + ":"
	// ----- disk ------
	inf_disk := exec.Command("df")
	res_disk, _ := inf_disk.Output()
	inf_disk_array := strings.Fields(string(res_disk))
	disk := "Disk:" + inf_disk_array[23]
	// ----- procesador -----

	return mem + disk
}

func (s Shell) processCommand(datoIn string) {
	array_datoIn := strings.Fields(datoIn)
	var shell *exec.Cmd
	if len(array_datoIn) > 1 {
		shell = exec.Command(array_datoIn[0], array_datoIn[1:]...) // el ... indica el resto de elementos del arraglo
	} else {
		shell = exec.Command(datoIn)
	}
	res, _ := shell.Output()

	// fmt.Println(datoIn)
	// fmt.Println(string(res))
	s.writer.WriteString(string(res) + "\v")
	s.writer.Flush()
}

func (s *Shell) mainLoop() {
	datoIn := ""
	res := false
	fmt.Println("--------SHELL OPERATIVOS------\n")
	fmt.Println("El Cliente se he conectado a al server con (ip:puerto) : (", s.socket.RemoteAddr(), ")\n")

	for datoIn != "exit" {
		if !res {
			res = s.logIn()
		} else {
			msg := s.reader
			datoIn, _ = msg.ReadString('\n')
			datoIn = strings.TrimRight(datoIn, "\r\n")
			if datoIn != "exit" {
				s.processCommand(datoIn)
			}

		}

	}
}

func main() {
	tcpAddress, _ := net.ResolveTCPAddr("tcp4", ":65432")
	SocketServer, _ := net.ListenTCP("tcp", tcpAddress) // Crea el socket servidor
	socket, _ := SocketServer.Accept()                  // Pone en modo escucha el socket y aca almacena todo lo que llega desde el cliente

	shell := InitShell(SocketServer, &socket)
	shell.mainLoop()
}
