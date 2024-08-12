#include <bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define pii pair<int,int>
#define forn for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;

signed main() {
    USM;

    //Tamanio del arreglo
    int n;cin>>n;
    vi arr(n);
    forn{
        cin>> arr[i];
    }
    for(int i=0;i<arr.size()-1;i++){
        for(int j=0;i<arr.size()-1;j++){
            if(arr[i] < arr[j] && i !=j){
                swap(arr[i],arr[j]);
            }
        }
    }

    return 0;
}
