Funcion CALCULOS <- CALCULOS(factorial,num)
	Mientras num>1 Hacer
		factorial=factorial*num;
		num=num-1;
	Fin Mientras
	Escribir Imprimaa(factorial);
Fin Funcion

Funcion  res2 <- MAS()
	res2=" ";
	Mientras res2 <> "S" y res2 <> "N" Hacer
		Escribir "Deseas calcular más factoriales (S/N):";
		Leer res2;
		res2 = Mayusculas(res2);
	Fin Mientras
Fin Funcion

Funcion Imprimaa <- Imprimaa (factorial)
	Escribir "Su factorial es: ";
	Escribir factorial;
Fin Funcion

Algoritmo Ejercicio6s3
	definir res Como Caracter;
	definir factorial Como Entero;
	res = "S";
	Mientras res=="S" Hacer
		Borrar Pantalla;
		factorial = 1;
		Escribir "Número: ";
		Leer num;
		Si num<0 Entonces
			Escribir "No tiene factorial";
		SiNo
		Escribir  CALCULOS(factorial,num);
		Fin Si
		res =  MAS();
	Fin Mientras
FinAlgoritmo

