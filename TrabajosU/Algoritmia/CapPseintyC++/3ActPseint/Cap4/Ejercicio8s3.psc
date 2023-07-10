Algoritmo Ejercicio8s3
	Definir p,imp,sw,i Como Entero;
	Borrar Pantalla;
	par = 0;
	impar = 0;
	sw = 0;
	i = 1;
	Mientras i <= 1000 Hacer
		Si sw = 0 Entonces
			imp = imp + i;
			sw = 1;
		SiNo
			p = p + i;
			sw = 0;
		Fin Si
		i = i + 1;
	Fin Mientras
	Escribir "La suma de los pares es: ";
	Escribir p;
	Escribir "La suma de los impares es: ";
	Escribir imp;
FinAlgoritmo
