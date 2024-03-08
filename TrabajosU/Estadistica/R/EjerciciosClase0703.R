Tredes=read.delim("clipboard",header=TRUE) # Trae los elementos que se han copiado
Tredes
names(Tredes)
Tredes$Tiempo.Uso.redes
attach(Tredes)
Tiempo.Uso.redes
# Tablas agrupadas por intervalos de clase
nclass.Sturges(Tiempo.Uso.redes) # Sugiere la cantidad de intervalos para agrupar por intervalos
class(Tiempo.Uso.redes)
Tiempo.Uso.redes=gsub(',','.',Tiempo.Uso.redes) # Cambia las comas por puntos
Tiempo.Uso.redesN=as.numeric(Tiempo.Uso.redes) # Casteamos el dato a numerico
class(Tiempo.Uso.redesN)
Tiempo.Uso.redesN
Tinv=data.frame(table(Tiempos=factor(cut(Tiempo.Uso.redesN,breaks = 8)))) # Crea un dataframe y agrupa por intervalos
View(Tinv)

# Construir tabla con frecuencia relativa
Tinv=transform(Tinv, fr=round(prop.table(Freq)*100,3))
# Histograma
hist(Tiempo.Uso.redesN, main="Histograma",xlab="Tiempo",ylab="Frecuencia")
# Diagrama de caja
boxplot(Tiempo.Uso.redesN,horizontal = T)
sort(Tiempo.Uso.redesN) # Ordena los datos

# Medidas de tendencia central
mean(Tiempo.Uso.redesN) # Media
median((Tiempo.Uso.redesN)) # Mediana
max(Tiempo.Uso.redesN) # Maximo
min(Tiempo.Uso.redesN) # Minimo
mean(Tiempo.Uso.redesN,0.05) # Media recortada al 5%

# instalar libreria
# install.packages("modeest")
library(modeest)

mfv(Tiempo.Uso.redesN)

sd(Tiempo.Uso.redesN) # Desviacion estandar
var(Tiempo.Uso.redesN) # Varianza

summary(Tiempo.Uso.redesN) # Resumen

quantile(Tiempo.Uso.redesN)
quantile(Tiempo.Uso.redesN, probs=0.75)
quantile(Tiempo.Uso.redesN, probs=0.9)
quantile(Tiempo.Uso.redesN, probs=c(0.1,0.5,0.8,0.9))

# Medidas de forma
# install.packages("moments")
library(moments)

skewness(Tiempo.Uso.redesN) # simetria
kurtosis(Tiempo.Uso.redesN) # Kurtosis
sd(Tiempo.Uso.redesN)/mean(Tiempo.Uso.redesN) # Coeficiente de asimetria

# install.packages("psych")
library(psych)

# Llamando datos desde excel
library(readxl)
datosRedesSocialesM = read_excel("C:/Users/Juan/JAristizabal/U/TrabajosU/Estadistica/R/datosRedesSocialesM.xlsx")
View(datosRedesSocialesM)
datosRedesSocialesM
names(datosRedesSocialesM)
datosRedesSocialesM$Edad
attach(datosRedesSocialesM)
class(Edad)
class(Género)

barplot(table(Edad))
hist(Edad)
skewness(Edad)

summary(Edad)
# install.packages("tidyverse")
library(tidyverse)
# install.packages("dplyr")
library(dplyr)

res = datosRedesSocialesM%>%group_by(`Redes sociales`)%>%
  summarise(media = mean(Edad, na.rm = TRUE ), 
            varianza = var(Edad, na.rm = TRUE))
res
View(res)
