Algoritmo Ejercicio9
	Definir res Como Caracter;
	Definir aa, sw, mes, dia Como Entero;
	res <- "S";
	Mientras res = "S" Hacer
		aa <- 0;
		Escribir "Año: ", Sin Saltar;
		Leer aa;
		Escribir "Mes: ", Sin Saltar;
		sw <- 0;
		Mientras sw = 0 Hacer
			mes <- 0;
			Leer mes;
			Si mes >= 1 Y mes <= 12 Entonces
				sw <- 1;
			Fin Si
		Fin Mientras
		sw <- 0;
		Escribir "Dia: ", Sin Saltar;
		Mientras sw = 0 Hacer
			dia <- 0;
			Leer dia;
			Si dia > 0 Y dia <= 31 Entonces
				Si mes = 2 Y aa = (aa/4)*4 Y dia <= 29 Entonces
					sw <- 1;
				Fin Si
				Si mes = 2 Y aa <> (aa/4)*4 Y dia <= 28 Entonces
					sw <- 1;
				Fin Si
				Si (mes = 4 O mes = 6 O mes = 9 O mes = 11) Y dia <= 30 Entonces
					sw <- 1;
				Fin Si
			Fin Si
		Fin Mientras
		Escribir "¿Desea continuar? - ";
		Leer res;
		res <- Mayusculas(res);
	FinMientras
FinAlgoritmo
