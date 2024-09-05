#include <bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define forn for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
const int mod = 1e9+7;

using namespace std;

signed main() {
    USM;

    int n,b;cin>>n>>b;
    vi arr(n);
    int pos_b = -1,final=0;
    forn{
        cin>>arr[i];
        if(arr[i] == b){
            pos_b = i;
        } 
    }
    if(pos_b == -1){
        cout << 0 << endl;
        return 0;
    }
    map<int,int> contador;
    contador[0] = 1;
    int balanceo = 0;
    for(int i=pos_b+1;i<n;i++){
        if(arr[i] > b){
            balanceo++;
        }
        else if(arr[i] < b){
            balanceo--;
        }
        contador[balanceo]++;
    }
    balanceo=0;
    for(int i=pos_b;i>=0;i--){
        if(arr[i] > b) balanceo++;
        else if(arr[i] < b) balanceo--; 
        final += contador[-balanceo];
    }
    cout << final << endl;
    return 0;
}
