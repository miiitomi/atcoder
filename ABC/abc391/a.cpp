#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<string> S{"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
    string d;
    cin >> d;
    int i = distance(S.begin(), find(S.begin(), S.end(), d));
    i = (i + 4) % 8;
    cout << S[i] << endl;    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
