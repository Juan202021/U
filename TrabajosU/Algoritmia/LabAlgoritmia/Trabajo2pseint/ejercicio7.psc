Algoritmo ejercicio7
	Escribir "***Programa para calcular la distancia entre dos puntos***";
	Definir x1, x2, y1, y2, xT, yT, distancia Como Real;
	Escribir "Digite la coordenada x del primer punto: ", sin saltar;
	Leer x1;
	Escribir "Digite la coordenada y del primer punto: ", sin saltar;
	Leer y1;
	Escribir "Digite la coordenada x del segundo punto: ", sin saltar;
	Leer x2;
	Escribir "Digite la coordenada y del segundo punto: ", sin saltar;
	Leer y2;
	xT <- x2-x1;
	yT <- y2-y1;
	distancia <- raiz(xT*xT + yT*yT);
	Escribir "La distancia entre los dos puntos es de: ", distancia;
	
FinAlgoritmo
