x0 = c(0.5,
       0.5,
       0.5,
       1.5,
       1.5,
       1.5,
       2.5,
       2.5,
       2.5,
       2.5,
       3.5,
       3.5,
       3.5,
       3.5)
y0 = c(64.7,
       86.1,
       92.1,
       132.9,
       202.1,
       223.6,
       231.5,
       365.3,
       382.3,
       413.5,
       447.2,
       466.7,
       493.7,
       563.8)
boxplot(x0,main="Densidades",ylab="Densidad",xlab="Datos")
boxplot(y0,main="Presiones",ylab="Presión",xlab="Datos")

x = c(37.7,
      65.5,
      93.3,
      100,
      121.1,
      148.8,
      176.6,
      204.4)
y = c(0.085,
      0.103,
      0.121,
      0.137,
      0.155,
      0.189,
      0.207,
      0.73)
boxplot(x,main="Temperatura",ylab="Temperatura (C°)",xlab="Datos")
boxplot(y,main="Conductividad Termica",ylab="Conductividad térmica",xlab="Datos")

x1 = c(3008,
       3150,
       3200,
       3810,
       4010,
       4300,
       4500,
       4650,
       4950)
y1 = c(1270,
       1390,
       1485,
       1550,
       1652,
       1665,
       1700,
       1760,
       1820)
boxplot(x1,main="Temperatura de escape",ylab="Temperatura (°F)",xlab="Datos")
boxplot(y1,main="Fuerza de impulso",ylab="Fuerza (N)",xlab="Datos")
