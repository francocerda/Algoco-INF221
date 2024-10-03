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
    int n, h;cin >> n >> h;
    vi estalacmita(h + 1, 0), estalactita(h + 1, 0);
    for (int i = 0; i < n / 2; i++) {
        int x;cin >> x;estalacmita[x]++;
        cin >> x;estalactita[x]++;
    }
    vi destruye(h + 1, 0);
    for (int i = 1; i <= h; i++) {
        estalacmita[i] += estalacmita[i - 1];
        estalactita[i] += estalactita[i - 1];
    }
    for (int i = 1; i <= h; i++) {
        destruye[i] = estalacmita[h] - estalacmita[i - 1] + estalactita[h] - estalactita[h - i];
    }
    int min_obstaculos = *min_element(destruye.begin() + 1, destruye.end());
    int count_min = count(destruye.begin() + 1, destruye.end(), min_obstaculos);

    cout << min_obstaculos << " " << count_min << endl;

    return 0;
}
