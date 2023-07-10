Algoritmo ejercicio6
	Definir i,c Como Entero;
	i = 1;
	c = 0;
	Mientras i<101 Hacer
		Si (i % 2 == 0) Y (i % 3 == 0) Entonces
			c = c + 1;
			Escribir i;
		finSi
		i = i +1;
	Fin Mientras
	Borrar Pantalla;
	Escribir "Los multiplos son: ",c;
	
FinAlgoritmo
