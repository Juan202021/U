import pandas as pd  
import numpy as np
import matplotlib
matplotlib.use("TkAgg")  # Forzar backend interactivo
import matplotlib.pyplot as plt
# import seaborn as sns

x = 10  
y = 4.6
z = True
s = "Hola Mundo"
print("x:",type(x))
print("y:",type(y))
print("z:",type(z))
print("s:",type(s))

# Operadores aritméticos
b = 3
print(x,b)
print("Suma:", x + b)  
print("Resta:", x - b)  
print("Multiplicación:", x * b)  
print("División:", x / b)  
print("División entera:", x // b)  
print("Módulo:", x % b)  
print("Exponente:", x ** b)  

# Operadores de comparación
print("¿x es igual x b?", x == b)  
print("¿x es diferente de b?", x != b)  
print("¿x es mayor que b?", x > b)  
print("¿x es menor que b?", x < b)  
print("¿x es mayor o igual que b?", x >= b)  
print("¿x es menor o igual que b?", x <= b)  

# Operadores lógicos
x = True
y = False

print("x AND y:", x and y)  
print("x OR y:", x or y)  
print("NOT x:", not x)  

# Operadores de asignación
c = 5
print("Valor inicial de c:", c)

c += 2  
print("c += 2 ->", c)

c -= 1  
print("c -= 1 ->", c)

c *= 3  
print("c *= 3 ->", c)

c /= 2  
print("c /= 2 ->", c)

c //= 2  
print("c //= 2 ->", c)

c %= 3  
print("c %= 3 ->", c)

c **= 2  
print("c **= 2 ->", c)

def evaluar_numero(numero):
    if numero > 0:
        print("El número es positivo.")
    elif numero < 0:
        print("El número es negativo.")
    else:
        print("El número es cero.")

# Pruebas con diferentes valores
numeros = [10, -5, 0, 3, -9]
for num in numeros:
    print(f"\nNúmero: {num}")
    evaluar_numero(num)

contador = 1
print("\nCiclo while contando hasta 5:")
while contador <= 5:
    print(contador)
    contador += 1


# Crear una lista
frutas = ["Manzana", "Banana", "Cereza"]
print("Lista inicial:", frutas)

# Añadir elementos
frutas.append("Naranja")  # Agrega al final
print("Después de append:", frutas)

frutas.insert(1, "Kiwi")  # Agrega en la posición 1
print("Después de insert:", frutas)

# Eliminar elementos
frutas.remove("Banana")  # Elimina el valor específico
print("Después de remove:", frutas)

eliminado = frutas.pop(2)  # Elimina por índice y devuelve el elemento
print(f"Después de pop (eliminado {eliminado}):", frutas)

del frutas[0]  # Elimina el primer elemento
print("Después de del:", frutas)

# Modificar elementos
frutas[0] = "Mango"
print("Después de modificar el primer elemento:", frutas)


# Recorrer con índices
print("\nRecorriendo con range(len()):")
for i in range(len(frutas)):
    print(f"Índice {i}: {frutas[i]}")

# Recorrer con enumerate()
print("\nRecorriendo con enumerate():")
for i, fruta in enumerate(frutas):
    print(f"Posición {i} -> {fruta}")



# URL de un archivo CSV público
url = "https://people.sc.fsu.edu/~jburkardt/data/csv/airtravel.csv"

# Cargar el CSV directamente desde la URL
df = pd.read_csv(url)

# Mostrar las primeras 5 filas
print("\nPrimeras 5 filas del dataset:")
print(df)

# Generación de datos de ejemplo
meses = ["Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio"]
ventas = [100, 150, 200, 250, 300, 400]
costos = [80, 120, 160, 200, 240, 350]

# 📊 **Gráfico de Líneas**
plt.figure(figsize=(8, 5))
plt.plot(meses, ventas, marker="o", linestyle="-", color="blue", label="Ventas")
plt.plot(meses, costos, marker="s", linestyle="--", color="red", label="Costos")

plt.title("Ventas y Costos Mensuales")
plt.xlabel("Meses")
plt.ylabel("Montos en USD")
plt.legend()
plt.grid(True)
plt.draw()
plt.show()

# 📊 **Gráfico de Barras**
plt.figure(figsize=(8, 5))
plt.bar(meses, ventas, color="green", alpha=0.7, label="Ventas")
plt.bar(meses, costos, color="orange", alpha=0.7, label="Costos")

plt.title("Comparación de Ventas y Costos")
plt.xlabel("Meses")
plt.ylabel("Montos en USD")
plt.legend()
plt.grid(axis="y", linestyle="--", alpha=0.7)
plt.show()

# 📊 **Gráfico de Dispersión**
beneficios = np.array(ventas) - np.array(costos)

plt.figure(figsize=(8, 5))
plt.scatter(ventas, beneficios, color="purple", alpha=0.8)

plt.title("Relación entre Ventas y Beneficios")
plt.xlabel("Ventas")
plt.ylabel("Beneficios")
plt.grid(True, linestyle="--", alpha=0.7)
plt.show()
