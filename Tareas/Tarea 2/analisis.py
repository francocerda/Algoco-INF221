import pandas as pd
import matplotlib.pyplot as plt

# Leer los resultados del archivo CSV
df = pd.read_csv("resultados.csv")

# Filtrar filas donde el tiempo es numérico
df_numeric = df[pd.to_numeric(df['Tiempo(ns)'], errors='coerce').notnull()]
df_numeric['Tiempo(ns)'] = df_numeric['Tiempo(ns)'].astype(float)
df_numeric['Tamaño'] = df_numeric['Tamaño'].astype(int)

# Convertir tiempos de nanosegundos a milisegundos para el análisis
df_numeric['Tiempo(ms)'] = df_numeric['Tiempo(ns)'] / 1e6

# Gráfico de tiempos vs tamaño de cadenas usando escala logarítmica
plt.figure(figsize=(10, 6))
for algoritmo in df_numeric['Algoritmo'].unique():
    subset = df_numeric[df_numeric['Algoritmo'] == algoritmo]
    plt.plot(subset['Tamaño'], subset['Tiempo(ms)'], marker='o', linestyle='-', label=algoritmo)

plt.title('Tiempos de Ejecución vs Tamaño de las Cadenas')
plt.ylabel('Tiempo (ms) (Escala Logarítmica)')
plt.xlabel('Tamaño de las Cadenas')
plt.yscale('log')  # Establecer escala logarítmica en el eje Y
plt.legend()
plt.grid(True, which="both", ls="--")
plt.tight_layout()
plt.show()
