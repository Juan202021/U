# Punto 1
# (a)
# Secuencias
a = seq(4,by=4,length=10)
b = seq(7,by=7,length=10)
c = seq(10,by=10,length=10)

# (b)
# matriz
abcmatriz = rbind(a,b,c)

# (c)
View(abcmatriz)

# Punto 2
# (a)
# Secuencia
d = seq(5,by=3,length=6)

# (b)
e = seq(15,by=-2,length=6)

# (c)
# Matriz por fila y por columna
amatriz = rbind(d,e)
bmatriz = cbind(d,e)

# (d)
# Multiplicacion de matrices
abmatriz = amatriz %*% bmatriz

# (e)
# Determinante
det(abmatriz)
# Inversa redondeada a 3 digitos despues de la coma
round(solve(abmatriz),digits=3)

# (f)
# Transpuesta
t(amatriz) + bmatriz

# Punto 3
# Dataframe
Materias = c(3,4,3,5)
Sexo = c("f","f","m","f")
Uso.de.Ruta = c(8,5,6,5)
Estado.Civil = c("Soltero","Soltero","Casado","Soltero")
Posee.Beca = c("no","no","si","no")

df = data.frame(Materias,Sexo,Uso.de.Ruta,Estado.Civil,Posee.Beca)
rownames(df) = c("Sistemas","Electronica","Biologia","Ambiental")
View(df)

# Punto 4
# La funcion View() invoca un visor de datos de tipo hoja de cálculo en un objeto R
# La funcion mean() es la función genérica para la media aritmética (recortada) de un conjunto de datos numericos.
# La funcion sd() es la encargada de calcular la desviacion estandar de un conjunto de datos.
# La funcion length() obtiene o establece la longitud de vectores (incluyendo listas) y factores, y de cualquier otro objeto R para el que se haya 
#             definido un método.
# La funcion rep() replica los elementos de un vector o lista.
# La funcion paste() se utiliza para concatenar cadenas de texto.
# La funcion str() se usa para mostrar la estructura de un objeto en R, proporcionando informacion sobre su clase y la estructura de sus componentes.
# La funcion subset() se utiliza para extraer un subconjunto de elementos de un vector, matriz o dataframe basado en condiciones especificas.
# La funcion merge() se emplea para combinar dos dataframes en base a una o varias columnas comunes.
