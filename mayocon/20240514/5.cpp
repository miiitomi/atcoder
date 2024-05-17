// https://atcoder.jp/contests/abc248/tasks/abc248_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    if (K == 1) {
        cout << "Infinity\n";
        return;
    }

    set<vector<int>> S;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            ll x1 = X[i], x2 = X[j], y1 = Y[i], y2 = Y[j];
            vector<int> v;
            for (int k = 0; k < N; k++) {
                ll x = X[k], y = Y[k];
                if ((x2-x1)*(y-y1) == (y2-y1)*(x-x1)) {
                    v.push_back(k);
                }
            }
            if ((int)v.size() >= K) {
                S.insert(v);
            }
        }
    }
    cout << S.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
