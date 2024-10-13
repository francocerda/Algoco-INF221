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

pair<int, int> rotar(pair<int,int> p){return pair<int,int>(p.second,p.first);}

bool cuadrado(pii rect1, pii rect2, pii rect3) {
    if (rect1.first == rect2.first && rect2.first == rect3.first) {
        if (rect1.second + rect2.second + rect3.second == rect1.first) return true;
        else return false;
    }

    if (rect1.first == rect2.first && rect1.second + rect2.second == rect3.first && rect1.first + rect3.second == rect3.first) return true;
    if (rect1.first == rect3.first && rect1.second + rect3.second == rect2.first && rect1.first + rect2.second == rect2.first) return true;
    if (rect2.first == rect3.first && rect2.second + rect3.second == rect1.first && rect2.first + rect1.second == rect1.first) return true;

    return false;
}

signed main() {
    USM;


    pii rect1, rect2, rect3;
    cin >> rect1.first >> rect1.second;
    cin >> rect2.first >> rect2.second;
    cin >> rect3.first >> rect3.second;

    bool flag = false;


    flag |= cuadrado(rect1, rect2, rect3);
    flag |= cuadrado(rect1, rect2, rotar(rect3));
    flag |= cuadrado(rect1, rotar(rect2), rect3);
    flag |= cuadrado(rect1, rotar(rect2), rotar(rect3));
    flag |= cuadrado(rotar(rect1), rect2, rect3);
    flag |= cuadrado(rotar(rect1), rect2, rotar(rect3));
    flag |= cuadrado(rotar(rect1), rotar(rect2), rect3);
    flag |= cuadrado(rotar(rect1), rotar(rect2), rotar(rect3));
  
    cout << (flag ? "Yes" : "No") << endl;
    

    return 0;
}
