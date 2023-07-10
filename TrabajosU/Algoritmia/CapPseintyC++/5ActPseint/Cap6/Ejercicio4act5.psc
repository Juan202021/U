Algoritmo Ejercicio4
	Definir col1, col2 Como Entero;
	Definir dibujo Como Caracter;
	col1 <- 4;
	col2 <- 4;
	dibujo <- "****";
	
	Escribir dibujo;
	Escribir dibujo;
	Mientras col1 <= 75 Y col2 <= 75 Hacer
		Si azar(2) <= 0 Entonces
			Escribir "    ";
			col1 = col1 + 4;
			Escribir dibujo;
		SiNo
			Escribir "    ";
			col2 = col2 + 4;
			Escribir dibujo;
		Fin Si
	Fin Mientras
	Escribir "El ganador es el caballo numero: ", Sin Saltar;
	Si col1 >= 75 Entonces
		Escribir "1";
	SiNo
		Escribir "2";
	Fin Si
FinAlgoritmo
