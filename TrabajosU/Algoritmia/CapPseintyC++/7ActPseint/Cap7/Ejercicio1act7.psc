Algoritmo Ejercicio1
	Definir num1,num2,sum, nume2 Como Entero;
	num1=-1;
	PRIMERNUM(num1);
	num2=-1;
	SEGUNDONUM(num2);
	sum=0;
	nume1=num1;
	Mientras num1<> 0 y num2 <> 0 Hacer
		sum=sum+num2;
		num1=num1-1;
	Fin Mientras
	Borrar Pantalla;
	Escribir "El producto de: ", nume1;
	Escribir "por ", num2;
	Escribir "es ", sum;
FinAlgoritmo

Funcion PRIMERNUM (num1 Por Referencia) 
	Mientras num1<0 Hacer
		Escribir "Número: ";
		Leer num1;
	Fin Mientras
Fin Funcion

Funcion SEGUNDONUM (num2 Por Referencia)
	Mientras num2<0 Hacer
		Escribir "Número: ";
		Leer num2;
	Fin Mientras
Fin Funcion
