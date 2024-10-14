#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> elemento_indice;
unordered_map<int, string> indice_a_nombre;
vector<int> relaciones[15];
vector<int> combinacion_optima;
int contador_combinaciones = 0;
int numero_elementos;
int orden_actual[15];
bool elementos_marcados[15];
bool primera_combinacion_encontrada = false;

void generar_combinacion(int nivel_actual) {
    if (nivel_actual > numero_elementos) {
        contador_combinaciones++;
        if (!primera_combinacion_encontrada) {
            combinacion_optima.insert(combinacion_optima.end(), orden_actual + 1, orden_actual + 1 + numero_elementos);
            primera_combinacion_encontrada = true;
        }
        return;
    }

    for (int i = 1; i <= numero_elementos; i++) {
        auto it = relaciones[i].end();
        if (nivel_actual > 1) {
            it = find(relaciones[i].begin(), relaciones[i].end(), orden_actual[nivel_actual - 1]);
        }
        if (!elementos_marcados[i] && it == relaciones[i].end()) {
            orden_actual[nivel_actual] = i; 
            elementos_marcados[i] = true;    
            generar_combinacion(nivel_actual + 1);
            elementos_marcados[i] = false;   
        }
    }
}

int main() {
    int cantidad_casos;
    cin >> cantidad_casos; 
    for (int caso = 0; caso < cantidad_casos; caso++) {
        contador_combinaciones = 0;
        elemento_indice.clear();
        indice_a_nombre.clear();
        for (int i = 0; i < 15; i++) {
            relaciones[i].clear();
        }
        memset(elementos_marcados, false, sizeof(elementos_marcados));
        combinacion_optima.clear();
        primera_combinacion_encontrada = false;

        cin >> numero_elementos; 
        for (int i = 1; i <= numero_elementos; i++) {
            string nombre_elemento;
            cin >> nombre_elemento; 
            elemento_indice[nombre_elemento] = i;
            indice_a_nombre[i] = nombre_elemento;
        }

        int cantidad_relaciones;
        cin >> cantidad_relaciones; 
        for (int i = 0; i < cantidad_relaciones; i++) {
            string elemento1, elemento2;
            cin >> elemento1 >> elemento2; 
            relaciones[elemento_indice[elemento1]].push_back(elemento_indice[elemento2]);
            relaciones[elemento_indice[elemento2]].push_back(elemento_indice[elemento1]);
        }

        generar_combinacion(1); 
        cout << contador_combinaciones << endl;
        for (int i = 0; i < numero_elementos; i++) {
            cout << indice_a_nombre[combinacion_optima[i]] << " "; 
        }
        cout << endl;
    }
    return 0;
}