Algoritmo Ejercicio6
	Definir res Como Caracter;
	Definir c Como Entero;
	Definir num Como Real;
	res <- "S";
	Mientras res = "S" Hacer
		num <- -1;
		Mientras num < 0 Hacer
			Escribir "Numero: ", Sin Saltar;
			Leer num;
		FinMientras
		c = 1;
		Mientras num >=10 Hacer
			num <- num / 10;
			c <- c + 1;
		FinMientras
		Escribir "El numero de cifras es: ", c;
		
		Escribir "¿Desea continuar? - ";
		Leer res;
		res <- Mayusculas(res);
		
	FinMientras
FinAlgoritmo
