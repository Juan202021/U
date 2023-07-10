Algoritmo Ejercicio6
	Definir op, fact, divisores Como Entero;
	Definir n Como Real;
	
	op = 0;
	fact <- 1;
	divisores <- 0;
	Borrar Pantalla;
	
	Escribir "Numero: ", Sin Saltar;
	Leer n;
	Mientras op <> 4 Hacer
		op = 0;
		Escribir "Menu de opciones";
		Escribir "1.- Comprobar si es primo";
		Escribir "2.- Factorial";
		Escribir "3.- Tabla de multiplicar";
		Escribir "4.- Salir del programa";
		Escribir "Elige opcion:";
		Leer op;
		Segun op Hacer
			1:
				Para i<-2 Hasta n-1 Con Paso 1 Hacer
					Si n MOD i = 0 Entonces
						divisores <- divisores + 1;
					Fin Si
				Fin Para
				Si divisores <> 0 Entonces
					Escribir "El numero NO es primo";
				SiNo
					Escribir "El numero es primo";
				Fin Si
			2:
				Para i<-1 Hasta n Con Paso 1 Hacer
					fact <- fact * i;
				Fin Para
				Escribir "El factorial de ", n," es: ", fact;
			3:
				Escribir "Tabla del ", n;
				Escribir "1 x ", n, " = ", 1*n;
				Escribir "2 x ", n, " = ", 2*n;
				Escribir "3 x ", n, " = ", 3*n;
				Escribir "4 x ", n, " = ", 4*n;
				Escribir "5 x ", n, " = ", 5*n;
				Escribir "6 x ", n, " = ", 6*n;
				Escribir "7 x ", n, " = ", 7*n;
				Escribir "8 x ", n, " = ", 8*n;
				Escribir "9 x ", n, " = ", 9*n;
				Escribir "10 x ", n, " = ", 10*n;
		Fin Segun
		
	Fin Mientras
FinAlgoritmo
