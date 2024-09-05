from collections import deque

def funcion(n_acciones, acciones):
    oferta = []
    demanda = []
    precio_stock = None

    for linea in acciones:
        partes = linea.split()
        accion = partes[0]
        tipo = int(partes[1])
        precio = int(partes[-1])

        if accion == "buy":
            demanda.append((precio, tipo))
            demanda.sort(reverse=True)  

        elif accion == "sell":
            oferta.append((precio, tipo))
            oferta.sort() 

        while oferta and demanda and demanda[0][0] >= oferta[0][0]:
            precio_oferta, accion_oferta = oferta[0]
            precio_demanda, accion_demanda = demanda[0]

            precio_transaccion = precio_oferta
            precio_stock = precio_transaccion

            if accion_demanda > accion_oferta:
                demanda[0] = (precio_demanda, accion_demanda - accion_oferta)
                oferta.pop(0)
            elif accion_demanda < accion_oferta:
                oferta[0] = (precio_oferta, accion_oferta - accion_demanda)
                demanda.pop(0)
            else:
                oferta.pop(0)
                demanda.pop(0)


        precio_oferta = oferta[0][0] if oferta else "-"
        precio_demanda = demanda[0][0] if demanda else "-" 
        print(f"{precio_oferta} {precio_demanda} {precio_stock if precio_stock else '-'}")


n = int(input().strip())

for _ in range(n):
    n_acciones = int(input().strip())
    acciones = [input().strip() for _ in range(n_acciones)]
    funcion(n_acciones, acciones)
