#hipotesis
install.packages("BSDA")
library("BSDA")
#z.test(Dat, mu=0, sigma.x=##, conf.level=NC,alternative = "t") ## para el intervalo colocar mu=0
#z.test(Dat, mu=m0, sigma.x=##, conf.level=NC,alternative = "t,l,g") ## para cualquier hipotesis
#z.test(Dat1, sigma.x=0.09,DAt2, sigma.y=1.1, mu=M0,alternative = "t,l,g",conf.level = 0.95)

#SUpuesto, normalidad una muestra
#Prueba de Shapiro
#shapiro.test(Variable)
#install.packages(nortest)
#library(nortest)
#lillie.test(Variable) prueba de Kolmogorov y Smirnov

#supuesto, normalidad, homocedadticidad, muestras independientes
#wilcox.test(DT, mu=#,alternative = "t") #para una muestra cuando no satisface normalidad
wilcox.test(Dep, mu=8,alternative = "t",conf.level = 0.93 )
#t.test(dat,mu=mo,alternative = "t,l,g",conf.level = NC)
#dos condiciones verificar homocedasticidad
var.test(DT1, DT2)
#t.test(DT1,DT2,alternative="t,l,g",conf.level = N.c,var.equal = FALSE o TRUE)
#no normales prueba no parametrica

#wilcox.test(DT1,DT2, alternative = "t",parired=F) # muestras independientes mann Whitney
#wilcox.test(TDT1,DT2,alternative="g",paired=TRUE) Pareadas

###vERIFICAR EL INTERVALO DE CONFIANZA DADO POR EL PROGRAMA Y EL PROCESO A MANO
###prueba de hipotesis e intervalo de confianza proporciones

#TeachingDemos debe estar activa
prop.test(78,225,conf.level = 0.98,correct=FALSE,
          alternative = "two.sided", p = NULL) ##intervalo propor=NULL
prop.test(78,225,conf.level = 0.98,correct=FALSE,alternative = "g", p = 0.3) #hipotesis