#include <bits/stdc++.h>
#define int long long 
#define vi vector<char>
#define vii vector<vector<char>>
#define pii pair<int,int>
#define forn for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;


vii xd = {
    {'A','B','C','D'},
    {'E','F','G','H'},
    {'I','J','K','L'},
    {'M','N','O','.'}

};


int scatter(vii x,vii y){
    int suma = 0;

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(x[i][j] == y[i][j]){
                continue;
            }
            else if(x[i][j] == '.'){
                continue;
            }
            else{
                for(int k=0;k<4;k++){
                    for(int l=0;l<4;l++){
                        if(x[i][j] == y[k][l]){
                            suma += abs(i-k) + abs(j-l);
                        }
                    }
                }
                
            }
            
        }
    }

    return suma;

}



signed main() {
    USM;

    vii matrix(4,vi(4));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> matrix[i][j];
        }
    }

    cout << scatter(xd,matrix) << endl;


    


    
    return 0;
}
