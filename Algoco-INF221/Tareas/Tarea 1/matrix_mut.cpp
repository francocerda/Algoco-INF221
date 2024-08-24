#include <bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define forn for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;


vii result_matrix(vii matrix_1,vii matrix_2){

    for(int i=0;i<n;i++){
        for(int i=0;i<n;i++){
            for(int i=0;i<n;i++){
                
            }

        }
    }



}









signed main() {
    USM;

    int fila_1;cin>>fila_1;
    int columna_1;cin>>columna_1;
    vii matrix_1(fila_1,vector<int> (columna_1));//Inicializo el tamaño de mi matriz
    for(int i=0;i<fila_1;i++){
        for(int i=0;i<columna_1;i++){
            cin >> matrix_1[fila_1][columna_1];
        }
    }
    int fila_2;cin>>fila_2;
    int columna_2;cin>>columna_2;
    vii matrix_2(fila_2,vector<int> (columna_2));//Inicializo el tamaño de mi matriz
    for(int i=0;i<fila_2;i++){
        for(int i=0;i<columna_2;i++){
            cin >> matrix_1[fila_2][columna_2];
        }
    }


    
    return 0;
}
