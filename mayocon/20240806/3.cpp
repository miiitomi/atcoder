// https://atcoder.jp/contests/abc199/tasks/abc199_c
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
    string S;
    cin >> S;
    string S1 = S.substr(0, N), S2 = S.substr(N, 2*N);
    int Q;
    cin >> Q;
    while (Q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            a--; b--;
            if (b < N) swap(S1[a], S1[b]);
            else if (N <= a) swap(S2[a-N], S2[b-N]);
            else swap(S1[a], S2[b-N]);
        } else {
            swap(S1, S2);
        }
    }
    cout << S1 << S2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
