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

signed main() {
    USM;

    int n;cin>>n;
    set<int> arr_A,arr_B;
    for(int i=0;i<n;i++){
        int a,b;cin>> a>>b;
        arr_A.insert(a);arr_B.insert(b);
        auto A_inicio = arr_A.begin();
        auto B_inicio = arr_B.begin();
        auto A_fin = arr_A.end();
        auto B_fin = arr_B.end();
        if(*(A_fin--) <= *(B_fin--)){
            if(*A_inicio >= *B_inicio){
                cout << *A_inicio+*(B_fin--) << endl;
                
                
            }
            else{
                cout << *B_inicio+*(A_fin--) << endl;
            
            }
        }
        else{

            cout << *(B_fin--) + *A_inicio << endl;

        }
    }
        
    
    return 0;
}
