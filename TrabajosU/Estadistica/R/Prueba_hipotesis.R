#hipotesis
#install.packages("BSDA")
library("BSDA")
#z.test(Dat, mu=0, sigma.x=##, conf.level=NC,alternative = "t") ## para el intervalo colocar mu=0
#z.test(Dat, mu=m0, sigma.x=##, conf.level=NC,alternative = "t,l,g") ## para cualquier hipotesis
#z.test(Dat1, sigma.x=0.09,DAt2, sigma.y=1.1, mu=M0,alternative = "t,l,g",conf.level = 0.95)

#SUpuesto, normalidad una muestra
#supuesto, normalidad, homocedadticidad, muestras independientes
#wilcox.test(DT, alternative = "t"

#t.test(dat,mu=mo,alternative = "t,l,g",conf.level = NC)
#t.test(DT1,DT2,alternative="t,l,g",conf.level = N.c,var.equal = FALSE o TRUE)
#wilcox.test(TDT1,DT2,alternative="g",paired=TRUE) Pareadas
#wilcox.test(DT1,DT2, alternative = "t",parired=F) #mann Whitney


M1=c(14.0, 14.3, 12.2, 15.1)
M2=c(12.1, 13.6, 11.9, 11.2)

#Verificar si las poblaciones se distribuyen normal
shapiro.test(M1)
boxplot(M1)
shapiro.test(M2)

#Principio de homocedasticidad
var.test(M1,M2,conf.level = 0.9)

#Hipotesis de media, asumiendo independecia
t.test(M1,M2,mu=0,alternative = "t",conf.level = 0.9,var.equal = T,paired = FALSE)


mean(M1)
sd(M1)
mean(M2)
sd(M2)
(var(M1)*3+var(M2)*3)/6
t.test(M1,M2,mu=0,alternative ="t",var.equal=T,conf.level =0.9 )
qt(0.95,6,lower.tail = T)
#varianza iguales--principio de homocedasticidad
var.test(M1,M2,conf.level = 0.9)
var(M1)/var(M2)
qf(0.1,3,3,lower.tail = F)
#