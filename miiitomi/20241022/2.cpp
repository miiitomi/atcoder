// https://atcoder.jp/contests/abc094/tasks/arc095_a
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
    vector<int> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];
    vector<int> Y = X;
    sort(Y.begin(), Y.end());
    for (int x : X) {
        if (x <= Y[N/2-1]) {
            cout << Y[N/2] << "\n";
        } else {
            cout << Y[N/2-1] << "\n";
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
