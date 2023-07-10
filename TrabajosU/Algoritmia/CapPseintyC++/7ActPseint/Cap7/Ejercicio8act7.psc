Algoritmo Ejercicio8
	Definir n, a, b, c Como Entero;
	n <- 0;
	a <- 0;
	b <- 1;
	c <- 0;
	
	Escribir "Numero de terminos: ", Sin Saltar;
	Leer n;
	Mientras n > 0 Hacer
		Escribir a;
		c <- a + b;
		a <- b;
		b <- c;
		n <- n - 1;
	Fin Mientras
	
FinAlgoritmo
