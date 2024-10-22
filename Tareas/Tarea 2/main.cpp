#include <bits/stdc++.h>
#include <chrono> 
#include <fstream> // Para leer y escribir archivos
#define int int64_t 
#define vi std::vector<int>
#define vii std::vector<std::vector<int>>
#define pii std::pair<int,int>
#define forn for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;
using namespace chrono; 

// Funciones de costos para las operaciones
int costo_sub(char a, char b) { return (a == b) ? 0 : 2; }
int costo_ins(char b) { return 1; }
int costo_del(char a) { return 1; }
int costo_trans(char a, char b) { return (a != b) ? 1 : 0; }

// Algoritmo de fuerza bruta
int edicion_fuerza_bruta(string s1, string s2, int i, int j) {
    if (i == s1.size()) return (s2.size() - j) * costo_ins(' ');
    if (j == s2.size()) return (s1.size() - i) * costo_del(' ');

    int costo = costo_sub(s1[i], s2[j]) + edicion_fuerza_bruta(s1, s2, i + 1, j + 1);
    costo = min(costo, costo_ins(s2[j]) + edicion_fuerza_bruta(s1, s2, i, j + 1));
    costo = min(costo, costo_del(s1[i]) + edicion_fuerza_bruta(s1, s2, i + 1, j));

    if (i + 1 < s1.size() && j + 1 < s2.size() && s1[i] == s2[j + 1] && s1[i + 1] == s2[j]) {
        costo = min(costo, costo_trans(s1[i], s1[i + 1]) + edicion_fuerza_bruta(s1, s2, i + 2, j + 2));
    }
    return costo;
}

// Algoritmo de programación dinámica
int edicion_dp(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vii dp(n + 1, vi(m + 1, 0));
    for (int i = 1; i <= n; ++i) dp[i][0] = dp[i - 1][0] + costo_del(s1[i - 1]);
    for (int j = 1; j <= m; ++j) dp[0][j] = dp[0][j - 1] + costo_ins(s2[j - 1]);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = min({
                dp[i - 1][j - 1] + costo_sub(s1[i - 1], s2[j - 1]),
                dp[i - 1][j] + costo_del(s1[i - 1]),
                dp[i][j - 1] + costo_ins(s2[j - 1])
            });
            if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) {
                dp[i][j] = min(dp[i][j], dp[i - 2][j - 2] + costo_trans(s1[i - 1], s1[i - 2]));
            }
        }
    }
    return dp[n][m];
}

// Leer el archivo de casos de prueba
void leer_casos_prueba(string filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "No se pudo abrir el archivo " << filename << endl;
        return;
    }

    string s1 = "", s2 = "", line;
    string caso_actual = "";
    ofstream resultados("resultados.csv"); // Guardar resultados en archivo CSV
    resultados << "Caso,Algoritmo,Distancia,Tiempo(ns),Tamaño\n"; // Agregar columna Tamaño
    
    while (getline(file, line)) {
        // Ignorar líneas vacías
        if (line.empty()) continue;

        // Verificar si es un caso
        size_t pos_caso = line.find("Caso");
        if (pos_caso != string::npos) {
            caso_actual = line.substr(pos_caso, line.find(':') - pos_caso);
            continue;
        }

        // Verificar si es S1
        size_t pos_s1 = line.find("S1:");
        if (pos_s1 != string::npos) {
            s1 = line.substr(pos_s1 + 3); // Extraer después de "S1:"
            // Eliminar espacios iniciales
            s1.erase(0, s1.find_first_not_of(" \t"));
            // Eliminar comillas simples
            if (s1.size() >= 2 && s1.front() == '\'' && s1.back() == '\'') {
                s1 = s1.substr(1, s1.size() - 2);
            }
            continue;
        }

        // Verificar si es S2
        size_t pos_s2 = line.find("S2:");
        if (pos_s2 != string::npos) {
            s2 = line.substr(pos_s2 + 3); // Extraer después de "S2:"
            // Eliminar espacios iniciales
            s2.erase(0, s2.find_first_not_of(" \t"));
            // Eliminar comillas simples
            if (s2.size() >= 2 && s2.front() == '\'' && s2.back() == '\'') {
                s2 = s2.substr(1, s2.size() - 2);
            }

            // Procesar las cadenas s1 y s2
            int tamano_total = s1.size() + s2.size();

            // Ejecutar fuerza bruta solo si la longitud total es <= 12
            if (tamano_total <= 12) {
                auto inicio_fb = high_resolution_clock::now();
                int resultado_fb = edicion_fuerza_bruta(s1, s2, 0, 0);
                auto fin_fb = high_resolution_clock::now();
                auto duracion_fb = duration_cast<nanoseconds>(fin_fb - inicio_fb);
                resultados << caso_actual << ",Fuerza Bruta," << resultado_fb << "," << duracion_fb.count() << "," << tamano_total << endl;
            } else {
                resultados << caso_actual << ",Fuerza Bruta,No ejecutado,Cadenas demasiado largas," << tamano_total << endl;
            }

            // Medir tiempo y ejecutar DP
            auto inicio_dp = high_resolution_clock::now();
            int resultado_dp = edicion_dp(s1, s2);
            auto fin_dp = high_resolution_clock::now();
            auto duracion_dp = duration_cast<nanoseconds>(fin_dp - inicio_dp);
            resultados << caso_actual << ",Programación Dinámica," << resultado_dp << "," << duracion_dp.count() << "," << tamano_total << endl;

            // Reiniciar s1 y s2 para el siguiente caso
            s1 = "";
            s2 = "";
            continue;
        }
    }
    resultados.close();
}

signed main() {
    leer_casos_prueba("casos_prueba.txt");
    return 0;
}
