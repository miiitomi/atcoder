// https://atcoder.jp/contests/cf16-final/tasks/codefestival_2016_final_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;

    ll X = -1, tmp = 0;
    for (ll i = 1; i <= N; i++) {
        tmp += i;
        if (tmp >= N) {
            X = i;
            break;
        }
    }
    vector<ll> V;
    for (ll i = X; i >= 1; i--) {
        if (i <= N) {
            N -= i;
            V.push_back(i);
        }
    }
    sort(V.begin(), V.end());
    for (ll v : V) {
        cout << v << "\n";
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
