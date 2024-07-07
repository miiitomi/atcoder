#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K, X;
    cin >> N >> K >> X;
    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        cout << a << " ";
    }
    cout << X << " ";
    for (int i = 0; i < N-K; i++) {
        int a;
        cin >> a;
        cout << a << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
