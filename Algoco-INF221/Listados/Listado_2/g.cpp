#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;


int main() {
    int long long n,m,res=0;
    cin >> n >> m;
    vector<int long long> v(n);
    for(int long long i = 0; i < n; i++) {
        int long long x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    int long long num;
    for(int long long i = 0; i < m; i++) {
        cin >> num;
        auto it = lower_bound(v.begin(), v.end(), num);
        res += (*it - num);
    }
    cout << res << endl;
    return 0;
}