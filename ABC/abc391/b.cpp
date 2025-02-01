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
    vector<string> S(N), T(M);
    for (string &s : S) cin >> s;
    for (string &t : T) cin >> t;

    for (int a = 0; a <= N-M; a++) {
        for (int b = 0; b <= N-M; b++) {
            bool ok = true;
            for (int i = 0; i < M && ok; i++) {
                for (int j = 0; j < M && ok; j++) {
                    if (S[a+i][b+j] != T[i][j]) ok = false;
                }
            }
            if (ok) {
                cout << a+1 << " " << b+1 << endl;
                return;
            }
        }
    }    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
