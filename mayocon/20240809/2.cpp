// https://atcoder.jp/contests/abc255/tasks/abc255_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(K);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    auto dist = [&](int i, int j) {
        return sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j])+0.0);
    };

    double l = 0, r = 1e+18;
    for (int k = 0; k < 100; k++) {
        double m = (l + r) / 2;
        bool is_ok = true;
        for (int i = 0; i < N; i++) {
            bool tmp = false;
            for (int j : A) {
                if (dist(i, j) <= m) tmp=true;
            }
            if (!tmp) is_ok = false;
        }

        if (is_ok) r = m;
        else l = m;
    }

    cout << l << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
