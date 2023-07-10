Algoritmo Ejercicio3
	Definir frase, letra, res Como Caracter;
	Definir longit, a, i Como Entero;
	Escribir "***Programa que cuenta las veces que se repite una letra en una cadena de texto***";
	res <- "S";
	Mientras res = "S" Hacer
		a <- 0;
		longit <- 0;
		Escribir "Introduce una frase: ";
		Leer frase;
		longit <- Longitud(frase);
		i <- 1;
		Escribir "Escriba la letra a buscar: ";
		Leer letra;
		Mientras i <= longit Hacer
			Si letra = SubCadena(frase,i,i) Entonces
				a <- a + 1;
			Fin Si
			i <- i + 1;
		Fin Mientras
		Escribir "El numero de veces que aparece la letra ", letra, sin saltar;
		Escribir " En la frase ", frase, " es de ", a;
		res <- " ";
		Mientras res <> "S" Y res <> "N" Hacer
			Escribir "Desea introducir mas frases (S/N):";
			Leer res;
			res <- Mayusculas(res);
		Fin Mientras
	Fin Mientras
	
FinAlgoritmo
