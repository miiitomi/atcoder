#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<string> S(N, string(N, '.'));
    for (int i = 1; i <= N; i++) {
        int j = N+1-i;
        if (i <= j) {
            for (int a = i; a <= j; a++) {
                for (int b = i; b <= j; b++) {
                    if (i % 2 == 1) S[a-1][b-1] = '#';
                    else S[a-1][b-1] = '.';
                }
            }
        }
    }
    for (auto &s : S) cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
