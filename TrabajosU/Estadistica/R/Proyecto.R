library(readxl)
library(dplyr)
library(tidyverse)
# Libreria para pasar las tablas a archivos word 
#library(officer) # (Se comenta porque genera error si se activa a la vez que la libreria readxl)

Datos_Produc_Agric <- read_excel("C:/Users/Juan/JAristizabal/U/TrabajosU/Estadistica/Datos Produc Agric.xlsx", 
                                 sheet = "Hoja1")
View(Datos_Produc_Agric)

Data = Datos_Produc_Agric 
attach(Data)

# ------------------------------------------------------------------------------
# Punto A) Realice un resumen con las variables, de manera que plantee las temáticas 
# dadas en estadística descriptiva y el análisis bivariado (tablas, graficas MTC, ML, 
# MD y MF) cada grupo tiene la posibilidad de plantear el análisis.

tabTb = Data %>% group_by(Data$DEPARTAMENTO) %>% filter(CULTIVO=='CACAO',DEPARTAMENTO=='SANTANDER' | DEPARTAMENTO=='ANTIOQUIA' | DEPARTAMENTO=='ARAUCA' | DEPARTAMENTO=='HUILA' | DEPARTAMENTO=='CESAR' | DEPARTAMENTO=='TOLIMA' | DEPARTAMENTO=='NARIÑO') %>%
  summarise(Media_A_Sembrada = round(mean(`Área Sembrada(ha)`,na.rm = T),2),
            Varianza_A_Sembrada = round(var(`Área Sembrada(ha)`,na.rm = T),2),
            Coeficiente_de_variacion_A_Sembrada = round(sd(`Área Sembrada(ha)`)/mean(`Área Sembrada(ha)`),2),
            Media_Produccion = round(mean(`Producción(t)`,na.rm = T),2),
            Varianza_Produccion = round(var(`Producción(t)`,na.rm = T),2),
            Coeficiente_de_variacion_Produccion = round(sd(`Producción(t)`)/mean(`Producción(t)`),2))
view(tabTb)

DataFiltrada = Data %>% group_by(Data$DEPARTAMENTO) %>% filter(CULTIVO=='CACAO',DEPARTAMENTO=='SANTANDER' | DEPARTAMENTO=='ANTIOQUIA' | DEPARTAMENTO=='ARAUCA' | DEPARTAMENTO=='HUILA' | DEPARTAMENTO=='CESAR' | DEPARTAMENTO=='TOLIMA' | DEPARTAMENTO=='NARIÑO')
plot(DataFiltrada$`Área Sembrada(ha)`,DataFiltrada$`Producción(t)`,ylab='Producción (t)',xlab='Área sembrada (ha)')

# Crea un documento de Word
doc <- read_docx()
# Agrega una tabla al documento
doc <- doc %>%
  body_add_table(tabTb)
# Guardar el documento de Word
print(doc, target = "tabla_editable.docx")

# ------------------------------------------------------------------------------
# Punto B) Realice un resumen descriptivo comparativo para la variable rendimiento, 
# según corresponda a los departamentos planteados de acuerdo al producto designado. 
# Tenga en cuenta la información presentada en la tabla, el análisis solamente debe 
# plantearse de manera descriptiva. NO DEBEN JUZGAR HIPÓTESIS NI ESTIMAR INTERVALOS 
# DE CONFIANZA.

tabR = Data %>% group_by(DEPARTAMENTO) %>% filter(CULTIVO=='CACAO',DEPARTAMENTO=='HUILA' | DEPARTAMENTO=='TOLIMA') %>%
  summarise(Media_rendimiento_cacao = round(mean(`Rendimiento(t/ha)`,na.rm = T),3),
            Mediana_rendimiento_cacao = median(`Rendimiento(t/ha)`,na.rm = T),
            Varianza_rendimiento_cacao = round(var(`Rendimiento(t/ha)`,na.rm = T),5),
            Coeficiente_variacion_rendimiento_cacao = sd(`Rendimiento(t/ha)`)/mean(`Rendimiento(t/ha)`) 
  ) 
view(tabR)

# Crea un documento de Word
doc <- read_docx()
# Agrega una tabla al documento
doc <- doc %>%
  body_add_table(tabR)
# Guardar el documento de Word
print(doc, target = "tabla_editable.docx")

par(mfrow=c(1,2))

dataFiltrada1 = Data %>% group_by(DEPARTAMENTO) %>% filter(CULTIVO=='CACAO',DEPARTAMENTO=='HUILA')
dataFiltrada2 = Data %>% group_by(DEPARTAMENTO) %>% filter(CULTIVO=='CACAO',DEPARTAMENTO=='TOLIMA')
hist(dataFiltrada1$`Rendimiento(t/ha)`,main='',xlab='Rendimiento cacao en Huila(t/ha)')
hist(dataFiltrada2$`Rendimiento(t/ha)`,main='',xlab='Rendimiento cacao en Tolima(t/ha)')

par(mfrow=c(1,1))
boxplot(dataFiltrada1$`Rendimiento(t/ha)`,dataFiltrada2$`Rendimiento(t/ha)`,names=c('Huila','Tolima'),ylab='Rendimiento del cacao (t/ha)')

# ------------------------------------------------------------------------------
# Punto C) Evalué la existencia de relación entre el área sembrada y cosechada, 
# usando técnicas descriptivas

# Covarianza
cov(`Área Sembrada(ha)`,`Área Cosechada(ha)`)
# Coeficiente de correlacion
cor(`Área Sembrada(ha)`,`Área Cosechada(ha)`)

tabla = Data %>% summarise(Covarianza = cov(`Área Sembrada(ha)`,`Área Cosechada(ha)`),
                           Coeficiente_de_correlacion = cor(`Área Sembrada(ha)`,`Área Cosechada(ha)`),
                           Coeficiente_de_variacion_A_Sembrada = sd(`Área Sembrada(ha)`)/mean(`Área Sembrada(ha)`),
                           Coeficiente_de_variacion_A_Cosechada = sd(`Área Cosechada(ha)`)/mean(`Área Cosechada(ha)`))
view(tabla)

# Crea un documento de Word
doc <- read_docx()

# Agrega una tabla al documento
doc <- doc %>%
  body_add_table(tabla)

# Guardar el documento de Word
print(doc, target = "tabla_editable.docx")

par(mfrow=c(1,2))
plot(`Área Sembrada(ha)`,`Área Cosechada(ha)`)
boxplot(`Área Sembrada(ha)`,`Área Cosechada(ha)`,
        names = c("Área Sembrada", "Área Cosechada"),
        ylab = "Área (ha)")

# Punto D) Realice una prueba de hipótesis que le permita evaluar las hipótesis entre las dos 
# situaciones planteadas en el cuadro, use un nivel de significancia del 6%, evalúe los 
# supuestos necesarios para el análisis. (Tener en cuenta las temáticas planteadas en clase

# Ho: La media del area cosechada de cacao en el Huila es igual a la media area cosechada de cacao en el Tolima
# Ha: La media del area cosechada de cacao en el Huila es diferente a la media area cosechada de cacao en el Tolima

# (nivel de significancia del 6%) = 0,06

d_Huila = Data %>% filter(CULTIVO=="CACAO", DEPARTAMENTO=="HUILA") %>%
  summarise(
    Área_cosechada = `Área Cosechada(ha)`
  )
d_Tolima = Data %>% filter(CULTIVO=="CACAO", DEPARTAMENTO=="TOLIMA") %>%
  summarise(
    Área_cosechada = `Área Cosechada(ha)`
  )

view(d_Huila) # n=36
view(d_Tolima) # n=33

n_Huila = d_Huila$Área_cosechada
n_Tolima = d_Tolima$Área_cosechada

# Verificar supuesto de normalidad
shapiro.test(n_Huila) # No se distribuye normal
shapiro.test(n_Tolima) # No se distribuye normal

# Verificar supuesto de Homocedasticidad
var.test(n_Huila,n_Tolima,conf.level = 0.94)

# Juzgar la hipótesis e intervalo de confianza
wilcox.test(n_Huila,n_Tolima, alternative = "t",parired=F,conf.level = 0.94,mu=0,conf.int = T,na.rm=T,exact = F)

# Se concluye que, con un nivel de confianza del 94%, existe evidencia estadistica 
# para afirmar que la media del area cosechada de cacao en el Huila es igual a la 
# media del area cosechada de cacao en el Tolima

# Punto E) Realice un análisis para probar la hipótesis planteada en “una condición” en el
# cuadro según el grupo que le corresponda, juzgue la hipótesis tenga en cuenta las 
# temáticas dadas en clase.

# hipotesis: La media del área cosechada del Huila es a lo sumo 165

# Ho: La media del área de cacao cosechada del Huila es menor o igual a 165
# Ha: La media del área de cacao cosechada del Huila es mayor a 165

# Ya se verifico el supuesto de normalidad y se encontro que no se distribuye normal

# Juzgar la hipotesis
wilcox.test(n_Huila, mu=165,alternative = "g",conf.int = T,exact = F, conf.level = 0.94)

# Intervalos de confianza
wilcox.test(n_Huila, mu=165,alternative = "t",conf.int = T,exact = F, conf.level = 0.94)

# Se concluye que con un nivel de significancia del 6%, la media del área cosechada 
# del Huila es a lo sumo 165


# Punto F) Seleccione dos variables de acuerdo al producto asignado y establezca ecuación de 
# regresión entre área cosechada y producción

DatSinCeros <- read_excel("C:/Users/Juan/JAristizabal/U/TrabajosU/Estadistica/Datos Produc Agric.xlsx", 
                                 sheet = "DatSinCero")
View(DatSinCeros)

DatSinC = DatSinCeros 
attach(DatSinC)

# Regresion lineal
d = lm(DatSinC$`Producción(t)`~DatSinC$`Área Cosechada(ha)`)
summary(d)

# Ecuacion y = 4.335 + 0.576x

# Residuales
residuals(d)
# Revisar normalidad de los residuales con Shapiro
shapiro.test(residuals(d))

# Homocedasticidad de la regresion
#install.packages("lmtest")
library("lmtest")
bptest(d)

# Arreglo de la regresion
library(MASS)
bc = boxcox(d)

(lambda =bc $ x [which.max (bc $ y)])
#Transformar la variable con el lambda encontado

# Correccion de la regresion
regresion_arreglada = lm(DatSinC$`Producción(t)`^0.5~DatSinC$`Área Cosechada(ha)`)
summary(regresion_arreglada)

# Nueva ecuacion: y = 4.276 + 0.029x

shapiro.test(residuals(regresion_arreglada))
bptest(regresion_arreglada)

pt = Data %>% filter(CULTIVO=="CACAO",DEPARTAMENTO=="HUILA")
plot(pt$`Área Cosechada(ha)`,pt$`Producción(t)`, xlab="Área cosechada (ha)", ylab="Producción (t)")
plot(DatSinC$`Área Cosechada(ha)`,DatSinC$`Producción(t)`, xlab="Área cosechada (ha)", ylab="Producción (t)")

# Se concluye que las variables presentan una relacion lineal fuerte, dada por 
# la expresion anterior, obtenida mediante un proceso de regresión significante 
# en el que se encontro que cumple con los supuestos de normalidad y homocedasticidad 


