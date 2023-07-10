Algoritmo Ejercicio2
	Escribir "***Programa para calcular los numeros pares que existen entre dos numeros y sumarlos***";
	Definir res Como Caracter;
	Definir c, sum, num1, num2 Como Entero;
	res <- "S";
	Mientras res = "S" Hacer
		c <- 0;
		sum <- 0;
		num1 <- 0;
		num2 <- -999;
		Escribir "Escriba el numero menor:";
		Leer num1;
		Escribir "Escriba el numero mayor:";
		Mientras num1 >= num2 Hacer
			Leer num2;
		Fin Mientras
		num1 <- num1 + 1;
		Mientras num1 <= num2-1 Hacer
			Si num1 = trunc(num1/2)*2 Entonces
				Escribir num1;
				c <- c + 1;
				sum <- sum + num1;
			Fin Si
			num1 <- num1 +1;
		Fin Mientras
		Escribir "Numero de multiplos de 2: ", c;
		Escribir "Su suma es: ", sum;
		res <- " ";
		Mientras res <> "S" Y res <> "N" Hacer
			Escribir "Otra serie de numeros (S/N):";
			Leer res;
			res <- Mayusculas(res);
		Fin Mientras
	Fin Mientras
FinAlgoritmo
