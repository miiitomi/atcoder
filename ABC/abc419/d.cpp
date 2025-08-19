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
    string S, T;
    cin >> S >> T;
    vector<int> v(N+1, 0);
    while (M--) {
        int l, r;
        cin >> l >> r;
        l--;
        v[l]++;
        v[r]--;
    }
    for (int i = 0; i < N; i++) v[i+1] += v[i];
    for (int i = 0; i < N; i++) {
        if (v[i] % 2) swap(S[i], T[i]);
    }
    cout << S << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
