Algoritmo multiplosdetres
	Definir i, n, c Como Entero;
	i = 3 ;
	n = 0;
	c = 0;
	Escribir "Numero:" ;
	Leer n;
	Mientras i <= n Hacer
		Si i=trunc(i/3) * 3 Entonces
			Escribir i ;
			c = c+1;
		Fin Si
		i=i+1;
	Fin Mientras
	Escribir "El número de multiplos de 3 son:";
	Escribir c;
FinAlgoritmo
