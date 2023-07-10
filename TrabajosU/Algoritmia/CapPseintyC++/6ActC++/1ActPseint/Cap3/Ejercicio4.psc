Algoritmo numerosdelunoalcien
	Definir i, sumaimp,sumapar Como Entero;
	i=1;
	sumapar=0;
	sumaimp=0;
	Mientras i < 101 Hacer
		Escribir i;
		Si i=trunc(i/2)*2 Entonces
			sumapar = sumapar+i;
		SiNo
			sumaimp = sumaimp+i;
		Fin Si
		i = i+1;
	Fin Mientras
	Escribir "La suma de los pares es:";
	Escribir sumapar;
	Escribir "La suma de los impares es:";
	Escribir sumaimp;
	
FinAlgoritmo
