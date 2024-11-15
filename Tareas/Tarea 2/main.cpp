#include <bits/stdc++.h>
#include <chrono>
#include <fstream> 
#define int int64_t 
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define forn(n) for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;
using namespace chrono;

// Variables globales para almacenar los costos de cada operación
vi cost_insert(26), cost_delete(26);
vii cost_replace(26, vi(26));
vii cost_transpose(26, vi(26));

// Funciones para cargar los costos desde archivos
void cargar_costos_insercion(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "No se pudo abrir el archivo de inserción: " << filename << endl;
        return;
    }
    for (int i = 0; i < 26; ++i) {
        file >> cost_insert[i];
    }
    file.close();
}

void cargar_costos_eliminacion(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "No se pudo abrir el archivo de eliminación: " << filename << endl;
        return;
    }
    for (int i = 0; i < 26; ++i) {
        file >> cost_delete[i];
    }
    file.close();
}

void cargar_costos_sustitucion(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "No se pudo abrir el archivo de sustitución: " << filename << endl;
        return;
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            file >> cost_replace[i][j];
        }
    }
    file.close();
}

void cargar_costos_transposicion(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "No se pudo abrir el archivo de transposición: " << filename << endl;
        return;
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            file >> cost_transpose[i][j];
        }
    }
    file.close();
}

// Funciones de costos para las operaciones
int costo_sub(char a, char b) {
    return cost_replace[a - 'a'][b - 'a'];
}

int costo_ins(char b) {
    return cost_insert[b - 'a'];
}

int costo_del(char a) {
    return cost_delete[a - 'a'];
}

int costo_trans(char a, char b) {
    return cost_transpose[a - 'a'][b - 'a'];
}

// Algoritmo de fuerza bruta
int fuerza_bruta(string s1, string s2, int i, int j) {
    int costo_base = 0;
    if (i == s1.size()){
        for(int j=0;j<s2.size();j++){
            costo_base += costo_ins(s2[j]);
        }
        return costo_base;
    }


    if (j == s2.size()){
        for(int i=0;i<s1.size();i++){
            costo_base += costo_del(s1[i]);
        }
        return costo_base;
    }

    int costo = costo_sub(s1[i], s2[j]) + fuerza_bruta(s1, s2, i + 1, j + 1);
    costo = min(costo, costo_ins(s2[j]) + fuerza_bruta(s1, s2, i, j + 1));
    costo = min(costo, costo_del(s1[i]) + fuerza_bruta(s1, s2, i + 1, j));

    if (i + 1 < s1.size() && j + 1 < s2.size() && s1[i] == s2[j + 1] && s1[i + 1] == s2[j]) {
        costo = min(costo, costo_trans(s1[i], s1[i + 1]) + fuerza_bruta(s1, s2, i + 2, j + 2));
    }
    return costo;
}

// Algoritmo de dp
int programacion_dimanica(const string &s1,const string &s2){

    int n = s1.size();
    int m = s2.size();
    vii dp(n+1,vi(m+1,0));

    for(int i=1;i<=n;i++){
        dp[i][0] = dp[i-1][0] + costo_del(s1[i-1]); 
    }
    for(int j=1;j<=m;j++){
        dp[0][j] = dp[0][j-1] + costo_ins(s2[j-1]); 
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = min({
                dp[i-1][j] + costo_del(s1[i-1]),
                dp[i][j-1] + costo_ins(s2[j-1]),
                dp[i-1][j-1] + costo_sub(s1[i-1], s2[j-1])
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
    resultados << "Caso,Algoritmo,Distancia,Tiempo(µs),Tamaño\n"; // Agregar columna Tamaño
    
    while (getline(file, line)) {
        if (line.empty()) continue;

        size_t pos_caso = line.find("Caso");
        if (pos_caso != string::npos) {
            caso_actual = line.substr(pos_caso, line.find(':') - pos_caso);
            continue;
        }

        size_t pos_s1 = line.find("S1:");
        if (pos_s1 != string::npos) {
            s1 = line.substr(pos_s1 + 3);
            s1.erase(0, s1.find_first_not_of(" \t"));
            if (s1.size() >= 2 && s1.front() == '\'' && s1.back() == '\'') {
                s1 = s1.substr(1, s1.size() - 2);
            }
            continue;
        }

        size_t pos_s2 = line.find("S2:");
        if (pos_s2 != string::npos) {
            s2 = line.substr(pos_s2 + 3);
            s2.erase(0, s2.find_first_not_of(" \t"));
            if (s2.size() >= 2 && s2.front() == '\'' && s2.back() == '\'') {
                s2 = s2.substr(1, s2.size() - 2);
            }

            int tamano_total = max(s1.size(), s2.size());

            if (tamano_total <= 14) {
                auto inicio_fb = high_resolution_clock::now();
                int resultado_fb = fuerza_bruta(s1, s2, 0, 0);
                auto fin_fb = high_resolution_clock::now();
                auto duracion_fb = duration_cast<microseconds>(fin_fb - inicio_fb);
                resultados << caso_actual << ",Fuerza Bruta," << resultado_fb << "," << duracion_fb.count() << "," << tamano_total << endl;
            } else {
                resultados << caso_actual << ",Fuerza Bruta,No ejecutado,Cadenas demasiado largas," << tamano_total << endl;
            }

            auto inicio_dp = high_resolution_clock::now();
            int resultado_dp = programacion_dimanica(s1, s2);
            auto fin_dp = high_resolution_clock::now();
            auto duracion_dp = duration_cast<microseconds>(fin_dp - inicio_dp);
            resultados << caso_actual << ",Programación Dinamica," << resultado_dp << "," << duracion_dp.count() << "," << tamano_total << endl;

            s1 = "";
            s2 = "";
            continue;
        }
    }
    resultados.close();
}

signed main() {

    // Cargar costos desde archivos de texto
    cargar_costos_insercion("cost_insert.txt");
    cargar_costos_eliminacion("cost_delete.txt");
    cargar_costos_sustitucion("cost_replace.txt");
    cargar_costos_transposicion("cost_transpose.txt");

    // Leer casos de prueba
    leer_casos_prueba("casos_prueba.txt");

    return 0;
}
