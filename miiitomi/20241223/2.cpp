// https://atcoder.jp/contests/abc157/tasks/abc157_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> s(M), c(M);
    for (int i = 0; i < M; i++) cin >> s[i] >> c[i];
    int l = (N==2)*10 + (N==3)*100;
    int r = (N==1)*9+(N==2)*99+(N==3)*999;
    for (int x = l; x <= r; x++) {
        string t = to_string(x);
        bool ok = true;
        for (int i = 0; i < M; i++) {
            if (t[s[i]-1]-'0' != c[i]) ok = false;
        }
        if (ok) {
            cout << x << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
