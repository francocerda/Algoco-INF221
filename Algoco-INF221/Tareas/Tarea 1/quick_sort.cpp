#include <bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define pii pair<int,int>
#define forn for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;




int ordenar(vi &arr, int inicio, int final){

    int pivot = arr[final];
    for(int i=0;i<final-1;i++){
        if(arr[i]<pivot){
            swap(arr[i], arr[pivot]);

        }


    }


}




void quick_sort(){

}

signed main() {
    USM;

    int n;cin>>n;
    vi arr(n);
    forn{
        cin >> arr[i];
    }

    quick_sort();






    
    
    
    return 0;
}
