#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    pair<int,int> X;
    string S;
    cin >> S;
    X.first = 10*(S[0]-'0') + (S[1]-'0');
    X.second = S.back()-'0';
    if (X >= make_pair(38, 0)) cout << "1\n";
    else if (X >= make_pair(37, 5)) cout << "2\n";
    else cout << "3\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
