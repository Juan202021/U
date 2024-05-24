#permite realizar operaciones
#el separador de los decimales es punto (.) y separan los elemntos por (,)
4-5/6
4*67.9/sqrt(20)
sqrt(45)
2+5
4*5-18

3-4*3
log10(52)
log10(7)
log10(20)
sqrt(16)
125^(1/3)
sin(60)

## R diferencia mayúsculas y minúsculas
#genera secuencias de números
OP=c(3,4,5,6.7,6.9)
AP<-c(56,78,89.9,345)
a=c(2:16)
a
b=c(20:10)
b
d=(1:25)
d

#Generar secuencias de datos
A=seq(1:10)
A
seq(from=1, to=10,by=2) #otra forma
seq(1,10,2)   ##inicia en, #termina en, de cuanto
B=seq(1,by=4,length=(12)) # #inicial, cada cuanto presentando el valor, tamaño del arreglo
B
class(B)
length(B)
C=rep(seq(1,10,by=2),8) #repite la secuencia cierto n?mero de veces
C
length(C)


# se pueden generar arreglos matriciales, con el comando 
#matrix o array, 
# se debe especificar la dimensión
#dim=c(f,c)

x=seq(2,by=2,length=(5))
x
y=seq(5,by=5,length=(5))
y
mxy<-rbind(x,y) #genera una matriz 
#pegando los vectores en columnas cbind, rbind une los vectores por filas
mxy
mxyc =cbind(x,y)
mxyc
View(mxy)
view(mxyc)

###se puede generar un arreglo númerico en vector
xy=c(x,y)
xy

matrizxy=matrix(xy,ncol=2,byrow=FALSE) # similar a matxy=matrix(xy,ncol=2, byrow=FALSE)
matrizxy
matxyf=matrix(xy, ncol=5,byrow = TRUE)
matxyf

#### OTRA FORMA: si la matriz se llama xy, dim(xy)=c(2,5)
dim(xy)=c(2,5)
xy
xy[1,]##tomar una fila,xy[,1] toma la columna 1
xy[,3]


##para dar nombre a las filas o las columnas
dimnames(xy)=list(c("Hombres","Mujeres"))
xy
dimnames(xy)=list(NULL,c("Ambiental","Biologia","Electronica","Procesos","Sistemas")) ###para dar nombre a la columna
xy
#Otra opcion para dar nombre 
dimnames(xy)=list(c("Hombres","Mujeres"),c("Ambiental","Biologia","Electr?nica","Procesos","Sistemas"))###para dar nombre a fila y la columna
xy
View(xy)

#-------------|-----------|----------------

A=1:100  ####otra forma de crear secuencias de numeros
matA=matrix(A,ncol=10)
dimnames(matA)=list(NULL,c("A","B","C","D","E","A","B","C","D","E"))
#n=c("A","B","C","D","E","A","B","C","D","E")
#dimnames(matA)=list(NULL,n)
matA




g=array(1:4,c(2,3))###que hace?
g
##
####OPERACIONES ENTRE MATRICES

da=array(f,dim=c(4,5))
da

db=array(c(2:5),dim=c(4,5))
db
##suma y diferencia de matrices
da-db
da+db
#multiplicaci?n por un escalar
3*da
t(da) #traspuestas
t(da)%*%db #multplicar transpuesta de la matriz A por la matriz B
#colocar el nombre al objeto
dab=t(da)%*%db
dab
sum(t(dab)) #traza de una  matriz
det(dab)
solve(dab) #inversa
Ma<-matrix(c(5,1,1,3,0,0,2,0,1), nrow = 3)
det(Ma)
solve(Ma)

#-------------|-----------|----------------|
# CREACION DE UN DATAFRAME

# Definición de vectores
name <- c("Mercury", "Venus", "Earth",
          "Mars", "Jupiter", "Saturn",
          "Uranus", "Neptune")

type <- c("Terrestrial planet",
          "Terrestrial planet",
          "Terrestrial planet",
          "Terrestrial planet", "Gas giant",
          "Gas giant", "Gas giant", "Gas giant")

diameter <- c(0.382, 0.949, 1, 0.532,
              11.209, 9.449, 4.007, 3.883)

rotation <- c(58.64, -243.02, 1, 1.03,
              0.41, 0.43, -0.72, 0.67)

rings <- c(FALSE, FALSE, FALSE, FALSE, TRUE, TRUE, TRUE, TRUE)

# Crea un data frame de los vectores
planets_df <- data.frame(name, type, diameter, rotation, rings)
planets_df
View(planets_df)

#-------------|-----------|----------------|
# GRAFICAR UNA FUNCION

f <- function(x) {
  return(x^2 +3*x + 2)
}

# Crear un vector de valores de x en el intervalo [-5, 5]
x <- seq(-5, 5, length.out = 100)

# Calcular los valores correspondientes de y (f(x))
y <- f(x)

# Graficar la funcion
plot(x, y, type = "l", col = "blue", lwd = 2, 
     main = "Grafica de f(x) = x^2 + 3x + 2", 
     xlab = "x", ylab = "f(x)")

#Arreglar la cuadricula
abline(h = seq(min(y), max(y), by = 10), col = "gray", lty = "dotted")
abline(v = seq(min(x), max(x), by = 1), col = "gray", lty = "dotted")
