// https://atcoder.jp/contests/abc108/tasks/arc102_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll L;
    cin >> L;
    ll N = 1;
    while ((1LL << N) <= L) N++;
    vector<vector<ll>> V;
    for (int x = 1; x < N; x++) {
        V.push_back({x, x+1, 0});
        V.push_back({x, x+1, (1 << (x-1))});
    }
    ll P = (1LL << (N-1));
    for (int x = N-1; x >= 1; x--) {
        if (P + (1LL << (x-1)) <= L) {
            V.push_back({x, N, P});
            P += (1LL << (x-1));
        }
    }
    cout << N << " " <<V.size() << "\n";
    for (auto v : V) {
        cout << v[0] << " " << v[1] << " " << v[2] << "\n";
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
