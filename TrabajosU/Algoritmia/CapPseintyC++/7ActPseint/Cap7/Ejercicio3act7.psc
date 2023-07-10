Algoritmo Ejercicio3
	Definir res,nombre, maxnom, minnom Como Caracter;
	Definir sueldo, maxsuel, minsuel,cont Como Entero;
	
	res = "S";
	sueldo=0;
	maxsuel=0;
	minsuel=999999;
	cont=0;
	Mientras res="S" Hacer
		Borrar Pantalla;
		Escribir "Nombre: ";
		Leer nombre;
		Escribir "Sueldo: ";
		Leer sueldo;
		cont=cont+1;
		Si sueldo>maxsuel Entonces
			maxnom = nombre;
			maxsuel = sueldo;
		Fin Si
		Si sueldo<minsuel Entonces
			minnom=nombre;
			minsuel=sueldo;
		Fin Si
		res= " ";
		MAS(res);
	Fin Mientras
	Borrar Pantalla;
	Escribir "La persona que mas gana es: " , maxnom;
	Escribir "Su sueldo asciende a: ", maxsuel;
	Escribir "La de menor sueldo es: ", minnom ;
	Escribir "que solo gana: ", minsuel;
	Escribir "Datos introducidos: ",cont;
FinAlgoritmo
	
	Funcion MAS (res Por Referencia)
		res <- ' ';
		Mientras res <> "S" y res <> "N" Hacer
			Escribir "Mas lanzamientos (S/N)";
			Leer res;
			res <- Mayusculas(res);
		Fin Mientras
	Fin Funcion
	
	
