#include <bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;

bool es_vocal(char C) {
    static const string vocales = "AEIOU";
    return vocales.find(C) != string::npos;
}

bool verificar_condiciones(const string &S) {
    int count_vocales = 0, count_consonantes = 0;
    bool tiene_L = false;

    for(const char &c : S) {
        if (c == 'L') tiene_L = true;

        if(es_vocal(c)) {
            count_vocales++;
            count_consonantes = 0;
        } else {
            count_consonantes++;
            count_vocales = 0;
        }

        if(count_consonantes > 2 || count_vocales > 2) return false;
    }

    return tiene_L;
}

void backtracking(string &s, int idx, vector<int> &ways, int &ans) {
    if (idx == s.size()) {
        if (verificar_condiciones(s)) {
            int count = 1;
            for (int i = 0; i < s.size(); i++) {
                count *= ways[i];
            }
            ans += count;
        }
        return;
    }

    if (s[idx] != '_') {
        ways[idx] = 1;
        backtracking(s, idx + 1, ways, ans);
    }
    else {
        //caso L
        s[idx] = 'L';
        ways[idx] = 1;
        backtracking(s, idx + 1, ways, ans);
        //consonante
        s[idx] = 'B';
        ways[idx] = 20;
        backtracking(s, idx + 1, ways, ans);
        //vocal
        s[idx] = 'A'; 
        ways[idx] = 5;
        backtracking(s, idx + 1, ways, ans);

      
        s[idx] = '_';
        ways[idx] = 1;
    }
}

signed main() {
    USM;
    string S; cin >> S;
    int ans = 0;
    vector<int> ways(S.size(), 1);
    backtracking(S, 0, ways, ans);
    cout << ans << endl;
    return 0;
}
