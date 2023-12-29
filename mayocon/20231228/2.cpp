// https://atcoder.jp/contests/abc255/tasks/abc255_b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double d(ll x1, ll y1, ll x2, ll y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(K), X(N), Y(N);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i< N; i++) cin >> X[i] >> Y[i];

    double ans = -1;
    for (int i = 0; i < N; i++) {
        ll x1 = X[i], y1 = Y[i];
        double tmp = 1e+18;
        for (int k : A) {
            ll x2 = X[k], y2 = Y[k];
            tmp = min(tmp, d(x1, y1, x2, y2));
        }
        ans = max(ans, tmp);
    }

    cout << fixed << setprecision(10) << ans << endl;
}
