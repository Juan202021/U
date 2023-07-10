Algoritmo Ejercicio1
	Definir res Como caracter ;
	res <- "S";
	Mientras res = "S" Hacer
		Borrar Pantalla;
		Si azar(2) <= 0.5 Entonces
			Escribir "cara";
		SiNo
			Escribir "cruz";
		Fin Si
		MAS(res);
	Fin Mientras
FinAlgoritmo

Funcion MAS (res Por Referencia)
	res <- ' ';
	Mientras res <> "S" y res <> "N" Hacer
		Escribir "Mas lanzamientos (S/N)";
		Leer res;
		res <- Mayusculas(res);
	Fin Mientras
Fin Funcion

