import random
import string

# Función para generar una cadena aleatoria
def generar_cadena_aleatoria(longitud):
    return ''.join(random.choice(string.ascii_lowercase) for _ in range(longitud))

# Función para escribir los casos de prueba en un archivo de texto
def escribir_datasets_en_txt(filename):
    with open(filename, 'w') as f:
        # Caso 1: Cadenas vacías
        f.write("Caso 1: Cadenas vacias\n")
        f.write(f"S1: ''\nS2: ''\n\n")
        
        # Casos para Cadenas con caracteres repetidos (Caso 2)
        cadenas_repetidas = ['a'*n for n in range(1, 8)]  # Genera 'a', 'aa', ..., 'aaaaaaa'
        caso_numero = 2
        for cadena in cadenas_repetidas:
            f.write(f"Caso {caso_numero}: Cadenas con caracteres repetidos\n")
            f.write(f"S1: '{cadena}'\nS2: '{cadena[:len(cadena)//2]}'\n\n")
            caso_numero += 1

        # Casos para Cadenas con transposiciones necesarias (Caso 3)
        transposiciones = [('ab', 'ba'), ('abc', 'bac'), ('abcd', 'badc')]
        for s1, s2 in transposiciones:
            f.write(f"Caso {caso_numero}: Cadenas con transposiciones necesarias\n")
            f.write(f"S1: '{s1}'\nS2: '{s2}'\n\n")
            caso_numero += 1

        # Casos para Cadenas con inserciones y eliminaciones (Caso 4)
        inserciones_eliminaciones = [('hello', 'he'), ('testing', 'test'), ('example', 'ex')]
        for s1, s2 in inserciones_eliminaciones:
            f.write(f"Caso {caso_numero}: Inserciones y eliminaciones\n")
            f.write(f"S1: '{s1}'\nS2: '{s2}'\n\n")
            caso_numero += 1

        # Casos adicionales: Cadenas aleatorias de tamaño variable
        tamanos = [ (2, 2), (3, 3), (4, 4), (5, 5), (6, 6) ]  # Longitudes hasta 6 para fuerza bruta
        for longitud_s1, longitud_s2 in tamanos:
            cadena1 = generar_cadena_aleatoria(longitud_s1)
            cadena2 = generar_cadena_aleatoria(longitud_s2)
            f.write(f"Caso {caso_numero}: Cadenas aleatorias de longitudes {longitud_s1} y {longitud_s2}\n")
            f.write(f"S1: '{cadena1}'\nS2: '{cadena2}'\n\n")
            caso_numero += 1

        # Casos más largos para programación dinámica (no se ejecutará fuerza bruta)
        tamanos_dp = [ (8, 8), (10, 10), (12, 12), (15, 15), (20, 20), (30, 30), (50, 50),(75,75),(100,100) ,(150,150),(200,200)]  # Aumenta tamaños para DP
        for longitud_s1, longitud_s2 in tamanos_dp:
            cadena1 = generar_cadena_aleatoria(longitud_s1)
            cadena2 = generar_cadena_aleatoria(longitud_s2)
            f.write(f"Caso {caso_numero}: Cadenas largas para DP de longitudes {longitud_s1} y {longitud_s2}\n")
            f.write(f"S1: '{cadena1}'\nS2: '{cadena2}'\n\n")
            caso_numero += 1

# Llamada a la función para generar el archivo
escribir_datasets_en_txt("casos_prueba.txt")
