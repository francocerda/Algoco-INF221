import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import curve_fit

# Leer los resultados del archivo CSV
df = pd.read_csv("resultados.csv")

# Filtrar filas donde el tiempo es numérico y limpiar tipos de datos
df_numeric = df[pd.to_numeric(df['Tiempo(µs)'], errors='coerce').notnull()].copy()
df_numeric.loc[:, 'Tiempo(µs)'] = df_numeric['Tiempo(µs)'].astype(float)
df_numeric.loc[:, 'Tamaño'] = df_numeric['Tamaño'].astype(int)
df_numeric.loc[:, 'Tiempo(ms)'] = df_numeric['Tiempo(µs)'] / 1e3  # Convertir a ms para análisis

# Separar datos de Fuerza Bruta y Programación Dinámica
df_fb = df_numeric[df_numeric['Algoritmo'] == 'Fuerza Bruta']
df_dp = df_numeric[df_numeric['Algoritmo'] == 'Programación Dinamica']

# Definir funciones modelo para ajustar
def exponencial(x, a, b):
    return a * np.exp(b * x)

def cuadratica(x, a, b, c):
    return a * x**2 + b * x + c

# Ajuste para Fuerza Bruta (modelo exponencial)
x_fb = df_fb['Tamaño']
y_fb = df_fb['Tiempo(ms)']
params_fb, _ = curve_fit(exponencial, x_fb, y_fb, maxfev=10000)

# Ajuste para Programación Dinámica (modelo cuadrático)
x_dp = df_dp['Tamaño']
y_dp = df_dp['Tiempo(ms)']
params_dp, _ = curve_fit(cuadratica, x_dp, y_dp, maxfev=10000)

# Graficar resultados y ajustes
plt.figure(figsize=(12, 6))

# Fuerza Bruta
plt.subplot(1, 2, 1)
plt.scatter(x_fb, y_fb, color='blue', label="Datos Fuerza Bruta")
plt.plot(x_fb, exponencial(x_fb, *params_fb), color='darkblue', linestyle='--', label="Ajuste Exponencial")
plt.title("Tiempo de Ejecución vs Tamaño (Fuerza Bruta)")
plt.xlabel("Tamaño de las Cadenas")
plt.ylabel("Tiempo (ms) (Escala Logarítmica)")
plt.yscale("log")
plt.legend()
plt.grid(True, which="both", ls="--")

# Programación Dinámica
plt.subplot(1, 2, 2)
plt.scatter(x_dp, y_dp, color='orange', label="Datos Programación Dinámica")
plt.plot(x_dp, cuadratica(x_dp, *params_dp), color='darkorange', linestyle='--', label="Ajuste Cuadrático")
plt.title("Tiempo de Ejecución vs Tamaño (Programación Dinámica)")
plt.xlabel("Tamaño de las Cadenas")
plt.ylabel("Tiempo (ms)")
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()

# Imprimir los parámetros de ajuste para interpretación
print("Parámetros de ajuste para Fuerza Bruta (Exponencial):")
print(f"a = {params_fb[0]}, b = {params_fb[1]}")
print("\nParámetros de ajuste para Programación Dinámica (Cuadrática):")
print(f"a = {params_dp[0]}, b = {params_dp[1]}, c = {params_dp[2]}")
