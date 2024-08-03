// https://atcoder.jp/contests/abc314/tasks/abc314_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<vector<ll>> C(M);
    for (int i = 0; i < N; i++) {
        ll c;
        cin >> c;
        c--;
        C[c].push_back(i);
    }
    for (ll c = 0; c < M; c++) {
        for (int j = (int)C[c].size()-1; j >= 1; j--) {
            swap(S[C[c][j-1]], S[C[c][j]]);
        }
    }
    cout << S << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
