atributos = input().split()

numero_canciones = int(input())
lista_canciones = []
for i in range(numero_canciones):
    cancion = input().split()
    lista_canciones.append(cancion)

numero_ordenes = int(input())
lista_ordenes = []
for i in range(numero_ordenes):
    orden = input()
    lista_ordenes.append(orden)

for orden in lista_ordenes:
    indice = atributos.index(orden)
    lista_canciones = sorted(lista_canciones, key=lambda cancion: cancion[indice])
    
    print(' '.join(atributos))
    for cancion in lista_canciones:
        print(' '.join(cancion))
    print()




