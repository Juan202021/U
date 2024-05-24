library(car)
library(MASS)
library(lmtest)
regAz=read.delim("clipboard", header=T)
attach(regAz)
names(regAz)
plot(Temperatura,Azucar) #gráfico dispersión
cov(Temperatura,Azucar)  # covarianza
cor(Temperatura,Azucar)  #coeficiente de correlación
cor.test(Temperatura,Azucar) #test de
modrA=lm(Azucar~Temperatura)
modrA
summary(modrA)
ANaz=aov(modrA)
ANaz
summary(ANaz)
#verificación de supuestos
residuals(modrA)
shapiro.test(residuals(ANaz))
bptest(modrA)
######

#######
library(MASS)
boxcox(modr)
bc =boxcox (modr)
(lambda =bc $ x [which.max (bc $ y)])
#Transformar la variable con el lambda encontado =0.10101

modrCox=lm(Relacion^0.10~Temperatura)
summary(modrCox)
plot(fitted(modrCox),residuals(modrCox))
bptest(modrCox) #rechazar ho homogeneidad revisar literatura