// https://atcoder.jp/contests/abc141/tasks/abc141_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string S;
    cin >> S;
    if (S == "Sunny") cout << "Cloudy\n";
    else if (S == "Cloudy") cout << "Rainy\n";
    else cout << "Sunny\n";    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
