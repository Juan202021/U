Algoritmo Ejercicio2
	Definir num1,num2 Como Entero;
	Definir cociente Como Real;
		num1=-1;
		PRIMERNUM(num1);
		num2=-1;
		SEGUNDONUM(num2);
		cociente=0;
		nume1=num1;
		Borrar Pantalla;
		Si num2=0 Entonces
			Escribir "No se puede dividir por cero";
		SiNo
			Mientras num1>=num2 Hacer
				num1=num1-num2;
				cociente=cociente+1;
			Fin Mientras
			Escribir "La división de: ", nume1;
			Escribir "por ", num2;
			Escribir "cociente ", cociente;
			Escribir "resto ", num1;
		Fin Si
FinAlgoritmo

Funcion PRIMERNUM (num1 Por Referencia) 
	Mientras num1<0 Hacer
		Borrar Pantalla;
		Escribir "Dividendo: ";
		Leer num1;
	Fin Mientras
Fin Funcion

Funcion SEGUNDONUM (num2 Por Referencia)
	Mientras num2<0 Hacer
		Borrar Pantalla;
		Escribir "Divisor: ";
		Leer num2;
	Fin Mientras
Fin Funcion

