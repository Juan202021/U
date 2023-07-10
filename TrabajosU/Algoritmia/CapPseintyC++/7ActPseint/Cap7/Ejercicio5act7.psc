Algoritmo Ejercicio5
	Definir res Como Caracter;
	Definir a, b, c Como Entero;
	res <- "S";
	Mientras res = "S" Hacer
		Escribir "Coeficiente de segundo grado: ", Sin Saltar;
		Leer a;
		Escribir "Coeficiente de primer grado: ", Sin Saltar;
		Leer b;
		Escribir "Termino independiente: ", Sin Saltar;
		Leer c;
		Si (b*b-4*a*c) = 0 Entonces
			Escribir "Raiz doble: ";
			Escribir -b/(2*a);
		SiNo
			Si (b*b-4*a*c) > 0 Entonces
				Escribir "Raices distintas de valor: ";
				Escribir (-b + raiz(b*b-4*a*c)) / (2*a);
				Escribir (-b - raiz(b*b-4*a*c)) / (2*a);
			SiNo
				Escribir "Raices imaginarias: ";
				Escribir -b + raiz(-(b*b-4*a*c)) / (2*a);
				Escribir -b - raiz(-(b*b-4*a*c)) / (2*a);
			FinSi
		Fin Si
		Escribir "¿Desea continuar? - ";
		Leer res;
		res <- Mayusculas(res);

	Fin Mientras
FinAlgoritmo
