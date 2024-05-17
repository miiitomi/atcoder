// https://atcoder.jp/contests/abc255/tasks/abc255_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dist2(ll x1, ll y1, ll x2, ll y2) {
    return(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    double ans = 0.0;

    for (int i = 0; i < N; i++) {
        ll tmp = 1e+18;
        for (int j : A) {
            tmp = min(tmp, dist2(X[i], Y[i], X[j], Y[j]));
        }
        ans = max(ans, sqrt((double)tmp));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
