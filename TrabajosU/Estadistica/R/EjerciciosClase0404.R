library(readxl)
datosRedesSocialesM <- read_excel("C:/Users/Juan/JAristizabal/U/TrabajosU/Estadistica/datosRedesSocialesM.xlsx")
View(datosRedesSocialesM)

attach(datosRedesSocialesM) # Vuelve los datos en formato tabla
names(datosRedesSocialesM) # Determina nombre de las variables

class('redes sociales') # Identifica el tipo de variable
class('edad')

# Se debe cargar las librerias dplyr y tidyverse
library(dplyr)
library(tidyverse)

tabR = datosRedesSocialesM %>% group_by(`Redes sociales`) %>%
  summarise(Media = mean(`Tiempo Uso redes`,na.rm = T), 
            Mediana = median(`Tiempo Uso redes`,na.rm = T),
            Coeficiente_variacion = sd(`Tiempo Uso redes`,na.rm = T)/mean(`Tiempo Uso redes`,na.rm = T,digits = 2),
            Encuestados=n(),
            Percentil_90 = quantile(`Tiempo Uso redes`, probs = c(0.9)))
tabR
view(tabR)

boxplot(datosRedesSocialesM$`Tiempo Uso redes`~datosRedesSocialesM$`Redes sociales`)

library(ggplot2)

# install.packages('ggridges')
library(ggridges)
