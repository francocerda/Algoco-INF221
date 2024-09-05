#include<bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define forn for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;

// Algoritmo de Quick Sort
void quickSort(vi& arreglo, int bajo, int alto) {
    if (bajo < alto) {
        int indiceMedio = bajo + (alto - bajo) / 2;
        int pivote = arreglo[indiceMedio];
        swap(arreglo[indiceMedio], arreglo[alto]);  

        int i = (bajo - 1);
        for (int j = bajo; j <= alto - 1; j++) {
            if (arreglo[j] < pivote) {
                i++;
                swap(arreglo[i], arreglo[j]);
            }
        }
        swap(arreglo[i + 1], arreglo[alto]);  
        int indicePivote = i + 1;
        quickSort(arreglo, bajo, indicePivote - 1);
        quickSort(arreglo, indicePivote + 1, alto);
    }
}

// Algoritmo de Merge Sort
void merge(vi& arreglo, int izq, int medio, int der) {
    int tamIzq = medio - izq + 1;
    int tamDer = der - medio;
    vi subArregloIzq(tamIzq), subArregloDer(tamDer);
    for (int i = 0; i < tamIzq; i++) subArregloIzq[i] = arreglo[izq + i];
    for (int i = 0; i < tamDer; i++) subArregloDer[i] = arreglo[medio + 1 + i];
    int i = 0, j = 0, k = izq;
    while (i < tamIzq && j < tamDer) {
        if (subArregloIzq[i] <= subArregloDer[j]) arreglo[k] = subArregloIzq[i++];
        else arreglo[k] = subArregloDer[j++];
        k++;
    }
    while (i < tamIzq) arreglo[k++] = subArregloIzq[i++];
    while (j < tamDer) arreglo[k++] = subArregloDer[j++];
}

void mergeSort(vi& arreglo, int izq, int der) {
    if (izq < der) {
        int medio = izq + (der - izq) / 2;
        mergeSort(arreglo, izq, medio);
        mergeSort(arreglo, medio + 1, der);
        merge(arreglo, izq, medio, der);
    }
}

// Algoritmo de Bubble Sort
void ordenarBurbuja(vi& arreglo) {
    int tam = arreglo.size();
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                swap(arreglo[j], arreglo[j + 1]);
            }
        }
    }
}

// Algoritmo estándar de C++ (std::sort)
void ordenarEstandar(vi& arreglo) {
    sort(arreglo.begin(), arreglo.end());
}

// Funcion para medir y mostrar tiempos de ejecucion
void medirTiempo(void (*funcionOrdenar)(vi&), vi arreglo, const string& nombre) {
    auto inicio = chrono::high_resolution_clock::now();
    funcionOrdenar(arreglo);
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    cout << nombre << " tomo " << duracion.count() << " segundos." << endl;
}

// Funcion para QuickSort que incluye indices
void quickSortWrapper(vi& arreglo) {
    quickSort(arreglo, 0, arreglo.size() - 1);
}

// Funcion para MergeSort que incluye indices
void mergeSortWrapper(vi& arreglo) {
    mergeSort(arreglo, 0, arreglo.size() - 1);
}

// Funcion para generar inputs de prueba
vi generarInput(int tam, const string& tipo) {
    vi arreglo(tam);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000000);

    for (int i = 0; i < tam; ++i) {
        arreglo[i] = dis(gen);
    }

    if (tipo == "ordenado") {
        sort(arreglo.begin(), arreglo.end());
    } else if (tipo == "parcialmente_ordenado") {
        sort(arreglo.begin(), arreglo.end());
        shuffle(arreglo.begin() + tam / 4, arreglo.end(), gen);
    } else if (tipo == "inversamente_ordenado") {
        sort(arreglo.begin(), arreglo.end(), greater<int>());
    }

    return arreglo;
}

signed main() {
    int tam;
    string tipo;

    cout << "Ingrese el tamanio del input: ";cin >> tam;
    cout << "Ingrese el tipo de ordenamiento (ordenado, parcialmente_ordenado, inversamente_ordenado, desordenado): ";
    cin >> tipo;

    vi arreglo = generarInput(tam, tipo);

    // Generar copias del vector para cada algoritmo
    vi arr1 = arreglo;
    vi arr2 = arreglo;
    vi arr3 = arreglo;
    vi arr4 = arreglo;

    // Medir tiempo de ejecucion para cada algoritmo
    medirTiempo(quickSortWrapper, arr1, "QuickSort");
    medirTiempo(mergeSortWrapper, arr2, "MergeSort");
    medirTiempo(ordenarBurbuja, arr3, "BubbleSort");
    medirTiempo(ordenarEstandar, arr4, "Sort Estandar");

    return 0;
}
