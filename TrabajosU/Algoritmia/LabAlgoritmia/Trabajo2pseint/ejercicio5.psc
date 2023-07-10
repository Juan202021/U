Algoritmo ejercicio5
	Escribir "***Programa para calcular el area de un terreno***";
	Definir base, puntoAltTerreno, puntoBajTerreno, area1, area2, areaTotal Como Real;
	Escribir "Digite la base del terreno: ", sin saltar;
	Leer base;
	Escribir "Digite el valor del punto mas alto de la altura del terreno: ", sin saltar;
	Leer puntoAltTerreno;
	Escribir "Digite el valor del punto mas bajo de la altura del terreno: ", sin saltar;
	Leer puntoBajTerreno;
	area1 <- base * puntoBajTerreno;
	area2 <- base * (puntoAltTerreno - puntoBajTerreno) / 2;
	areaTotal <- area1 + area2;
	Escribir "El area del terreno es: ", areaTotal;
	
FinAlgoritmo
