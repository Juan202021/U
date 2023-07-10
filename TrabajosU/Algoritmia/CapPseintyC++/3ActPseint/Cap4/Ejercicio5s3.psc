Algoritmo Ejercicio5s3
	definir res Como Caracter;
	definir factorial Como Entero;
	res = "S";
	Mientras res=="S" Hacer
		Borrar Pantalla;
		factorial = 1;
		Escribir "Número: ";
		Leer numero;
		Si numero<0 Entonces
			Escribir "No tiene factorial";
		SiNo
			Mientras numero>1 Hacer
				factorial=factorial*numero;
				numero=numero-1;
			Fin Mientras
			Escribir "Su factorial es: ";
			Escribir factorial;
		Fin Si
		res=" ";
		Mientras res <> "S" y res <> "N" Hacer
			Escribir "Más factoriales (S/N):";
			Leer res;
			res = Mayusculas(res);
		Fin Mientras
	Fin Mientras
FinAlgoritmo
