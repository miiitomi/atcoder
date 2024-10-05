#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> P[i] >> B[i] >> Q[i];

    ll left = 0, right = 1e+9 + 1;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            ll tmp = INF;
            for (ll x = 0; x <= 100; x++) {
                ll a = x;
                ll r = max(m - A[i]*a, 0LL);
                ll b = (r + B[i]-1) / B[i];
                tmp = min(a*P[i] + b*Q[i], tmp);

                b = x;
                r = max(m - B[i]*b, 0LL);
                a = (r + A[i]-1) / A[i];
                tmp = min(a*P[i] + b*Q[i], tmp);
            }
            sum += tmp;
        }
        if (sum <= X) left = m;
        else right = m;
    }
    cout << left << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
