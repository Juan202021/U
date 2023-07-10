Algoritmo Ejercicio4
	Definir nume, num,may,men,i,sw Como Entero;
	Definir res Como Caracter;
	
	res="S";
	Mientras res="S" Hacer
		num=azar(100)+1;
		sw=0;
		i=0;
		men=1;
		may=100;
		
		Mientras sw <> 1 Hacer
			Borrar Pantalla;
			Escribir "El numero a adivinar está entre ", men;
			Escribir " y ", may;
			Escribir "Numero: " ;
			Leer nume;
			i=i+1;
			Si num=nume Entonces
				sw=1;
			SiNo
				Si num>nume Entonces
					men=nume;
				SiNo
					may=nume;
				Fin Si
			Fin Si
		Fin Mientras
		Borrar Pantalla;
		Escribir "Numero de intentos ", i;
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
