Algoritmo Ejercicio4
	Definir horas, minutos, segund Como Entero;
	Definir res Como Caracter;
	
	horas <- 0;
	minutos <- 0;
	segund <- 0;
	res <- "S";
	Escribir "***Programa reloj***";
	Escribir "Horas:";
	Leer horas;
	Escribir "Minutos:";
	Leer minutos;
	Escribir "Segundos:";
	Leer segund;
	
	Mientras res = "S" Hacer
		Mientras horas < 24 Hacer
			Mientras minutos < 60 Hacer
				Mientras segund < 60 Hacer
					Escribir "H:",horas, Sin Saltar;
					Escribir " M:",minutos, Sin Saltar;
					Escribir " S:",segund;
					segund <- segund + 1;
					Esperar 1 Segundos;
				Fin Mientras
				minutos <- minutos + 1;
				segund <- 0;
			Fin Mientras
			horas <- horas + 1;
			minutos <- 0;
		Fin Mientras
		horas <- 0;
	Fin Mientras
	
	
FinAlgoritmo
