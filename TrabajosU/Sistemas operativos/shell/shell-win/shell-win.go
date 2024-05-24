package main

import (
	"bufio"
	"crypto/sha256"
	"fmt"
	"net"
	"os"
	"os/exec"
	"strings"
)

type Shell struct {
	SocketClient *net.TCPConn
	readerInput  *bufio.Reader
	reader       *bufio.Reader
	writer       *bufio.Writer
}

func InitShell(SocketClient *net.TCPConn) Shell {
	return Shell{SocketClient: SocketClient,
		readerInput: bufio.NewReader(os.Stdin),
		reader:      bufio.NewReader(SocketClient),
		writer:      bufio.NewWriter(SocketClient)}
}

func (s Shell) askCredentials() (string, string) {
	var user string
	var password string

	fmt.Print("User: ")
	fmt.Scanf("%s", &user)
	fmt.Print("Password: ")
	fmt.Scanf("%s", &password)

	hash_password := sha256.Sum256([]byte(password)) // Realiza el hash de la contraseña
	hash := fmt.Sprintf("%x", hash_password)         // Convierte a hexadecimal
	return user, hash
}

func (s *Shell) logIn(user string, password string) string {
	s.writer.WriteString(user + ":" + password + "\n")
	s.writer.Flush()
	msg := s.reader
	res, _ := msg.ReadString('\n')
	res = strings.TrimRight(res, "\r\n")
	return res
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

func (s Shell) command(datoIn string) string {
	s.writer.WriteString(datoIn + "\n")
	s.writer.Flush()
	msg := s.reader
	res, _ := msg.ReadString('\v')
	res = strings.TrimRight(res, "\v")
	return res
}

func (s *Shell) mainLoop() {
	isUser := "0"
	datoIn := ""
	fmt.Println("--------SHELL OPERATIVOS------\n")
	fmt.Println("El Cliente se ha conectado a un server con (ip:port) : (", s.SocketClient.RemoteAddr(), ")\n")

	for datoIn != "exit" {
		if isUser != "1" {
			isUser = s.logIn(s.askCredentials())
			if isUser == "1" {
				fmt.Println("Successful login\n")
			} else {
				fmt.Println("Login incorrect\n")
				continue
			}
		}

		fmt.Print("-Oper# ")

		datoIn, _ = s.readerInput.ReadString('\n') // el _ indica una variable que almacena el mensaje de error, sin embargo la variable no se va a usar
		datoIn = strings.TrimRight(datoIn, "\r\n")

		if datoIn != "exit" {
			fmt.Println(s.command(datoIn))
		} else {
			s.writer.WriteString("exit\n")
			s.writer.Flush()
		}

	}
}

func main() {
	ip := "169.254.12.150"
	tcpAddress, _ := net.ResolveTCPAddr("tcp4", ip+":65432") // ip destino : puerto de comunicacion del server
	socketClient, _ := net.DialTCP("tcp", nil, tcpAddress)   // Crea el socket cliente

	shell := InitShell(socketClient)
	shell.mainLoop()
}
