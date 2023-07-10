Algoritmo ejercicio6
	Escribir "***Programa para calcular el area de una figura***";
	Definir radio, hipotenusa, altura, areaTriangulo, areaCirculo, areaTotal Como Reales;
	Escribir "Digite el radio: ", sin saltar;
	Leer radio;
	Escribir "Digite la hipotenusa: ", sin saltar;
	Leer hipotenusa;
	altura <- raiz(hipotenusa*hipotenusa - radio*radio);
	areaTriangulo <- radio * altura;
	areaCirculo <- (PI * radio*radio) / 2;
	areaTotal <- areaTriangulo + areaCirculo;
	Escribir "El area de la figura es: ", areaTotal;
	
FinAlgoritmo
