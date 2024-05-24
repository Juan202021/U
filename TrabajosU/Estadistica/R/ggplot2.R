#  ESTUDIO DE GGPLOT2 PARA ESTADISTICA

#------------||-------------------||---------------||
#CREACION DE UNA GRAFICA CON GGPLOT2

# Instalar y aplicar la libreria  
install.packages("ggplot2")
library(ggplot2)

#ESTRUCTURA
#ggplot(data = nombreDeLosDatos,         #crea el grid de fondo, la cuadricula
#      mapping = aes(x = ejeX)) +       #el operador '+' sirve para agregar dise�o
#a la grafica
#  geom_bar()      # GEOMETRIA: significa qué tipo de grafico utilizaremos



#------------||-------------------||---------------||


# CREACION DE UN HISTOGRAMA

ggplot(data = mtcars,
       mapping = aes(x = hp)) +                     #bins = '': cantidad de barras
  geom_histogram(bins = 7, fill = "purple", color = "black", alpha = 0.5) +  #alpha sirve para transparentar
  labs(title = "Histograma de Potencia del Motor",  # Titulo del gráfico
       x = "Potencia del Motor (hp)",              # Etiqueta del eje x
       y = "Frecuencia") +                          # Etiqueta del eje y
  theme_bw() 



#------------||-------------------||---------------
# Datos obtenidos de base de datos proporcionada por R llamada: iris
iris

# Exploración de datos y resumen estadístico para conocer la variable
summary(iris)

#Creacion de histograma, boxplot y dispersion.
#COMPARANDO LA LONGITUD DE LOS TRES TIPOS DE PETALOS A LA VEZ.

# Cargar la base de datos iris, otra forma de llamar los datos
data(iris)



# Creación de histograma
# Graficar el histograma de la longitud de los pétalos 
ggplot(iris, aes(x = Petal.Length)) +
  geom_histogram(binwidth = 0.8, fill = "skyblue", color = "black") +
  facet_wrap(~Species) + #divide el gráfico en múltiples paneles, uno para cada nivel de la variable Species
  labs(title = "Histograma de Longitud de Pétalos por Especie",
       x = "Longitud de P�talos",                        #labs(): cambiar nombres
       y = "Frecuencia") +
  theme_minimal()

# Creación de boxplot
# Graficar el boxplot de la anchura de los pétalos por especie
ggplot(iris, aes(x = Species, y = Petal.Width, fill = Species)) +
  geom_boxplot() +
  labs(title = "Boxplot de Anchura de Pétalos por Especie",
       x = "Especie",
       y = "Anchura de Pétalos") +
  theme_minimal()

# Creación de grafico de dispersion

# Graficar el grafico de dispersion entre la longitud y la anchura de los pétalos
ggplot(iris, aes(x = Petal.Length, y = Petal.Width)) +
  geom_point() +
  labs(title = "Grafico de Dispersi�on: Longitud vs. Anchura de Pétalos",
       x = "Longitud de Petalos",                 
       y = "Anchura de Petalos") +
  theme_minimal()

# Graficar el grafico de dispersion entre la longitud y la anchura de los petalos, 
#diferenciado por el color de los petalos
ggplot(iris, aes(x = Petal.Length, y = Petal.Width, color = Species)) +
  geom_point() +
  labs(title = "Grafico de Dispersi�on: Longitud vs. Anchura de Pétalos",
       x = "Longitud de Pétalos",                 
       y = "Anchura de Pétalos") +
  theme_minimal()



#------------||-------------------||---------------
# CREACION DE GRAFICAS CON GGPLOT2, UNIFICANDO 2 TIPOS DE GRAFICOS

# UNIFICAR BOXPLOT CON PUNTOS

ggplot(data = iris,
       mapping = aes(x = Species,
                     y = Petal.Width,
                     fill = Species)) +
  geom_boxplot() +
  geom_jitter()

# GRAFICAS DE PUNTOS Y LINEAS
ggplot(data = iris,
       mapping = aes(x = Sepal.Length,
                     y = Sepal.Width,
                     color = Species))  +
  geom_point() + # grafica de dispersion
  geom_smooth(method = 'lm') 
#geom_smooth() # linea de tendencia para cada especia
#geom_smooth(method = 'lm') dicha linea de tendencia se vuelve recta
#nos da a conocer la tendencia, en este caso es positiva

ggplot(data=iris,
       aes(x=Species))+geom_bar()+
  labs(title = "Grafico de barras",
       x = "Especies",size=10,                
       y = "Frecuencias",size=10)+
  theme(plot.title = element_text(size = 10, face = "bold")) ##que hace esta funci�n cambie los valores

##diagrama de puntos simple
ggplot(data=mtcars,aes(x=gear))+
  geom_dotplot(fill="purple4")

#grafica de puntos simples, por lo general se aplica cuando hay pocos datos
data("mtcars")
ggplot(data=mtcars,aes(x=gear))+
  geom_dotplot(fill="purple4")+
  labs(title = "",
       x = "Engranajes",size=10,                
       y = "Frecuencias",size=10)

stripchart(mtcars$gear,at=F,method = "stack",pch = 20)
table(mtcars$gear) #mediante esta tbla se verifica la frecuencia de ocurrencia 
#que presenta el digrama de punto simple