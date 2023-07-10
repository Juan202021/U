Algoritmo Ejercicio5
	Definir op Como Entero;
	Definir n1, n2 Como Real;
	
	op = 0;
	Borrar Pantalla;
	
	Escribir "Numero 1: ", Sin Saltar;
	Leer n1;
	Escribir "Numero 2: ", Sin Saltar;
	Leer n2;
	Mientras op <> 5 Hacer
		op = 0;
		Escribir "Menu de opciones";
		Escribir "1.- Suma";
		Escribir "2.- Resta";
		Escribir "3.- Multiplicación";
		Escribir "4.- Division";
		Escribir "5.- Salir del programa";
		Escribir "Elige opcion:";
		Leer op;
		Segun op Hacer
			1:
				Escribir "Su suma es: ", Sin Saltar;
				Escribir n1+n2;
			2:
				Escribir "Su resta es: ", Sin Saltar;
				Escribir n1-n2;
			3:
				Escribir "Su multiplicacion es: ", Sin Saltar;
				Escribir n1*n2;
			4:
				Escribir "Su division es: ", Sin Saltar;
				Escribir n1/n2;
		Fin Segun
		
	Fin Mientras
FinAlgoritmo
