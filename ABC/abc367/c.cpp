#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int N, K;
vector<int> R;
vector<vector<int>> W;

void f(vector<int> &V) {
    if ((int)V.size() == N) {
        ll sum = 0;
        for (ll x : V) sum += x;
        if (sum % K == 0) W.push_back(V);
        return;
    }
    int i = V.size();
    for (int x = 1; x <= R[i]; x++) {
        vector<int> NV = V;
        NV.push_back(x);
        f(NV);
    }
}

void solve() {
    cin >> N >> K;
    R.resize(N);
    for (int i = 0; i < N; i++) cin >> R[i];
    vector<int> V;
    f(V);
    for (auto &v : W) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << "\n";
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
