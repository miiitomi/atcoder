#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, sum = 0;
    cin >> N >> M;
    vector<pair<ll, ll>> P(M);
    for (int i = 0; i < M; i++) {
        cin >> P[i].first;
        P[i].first--;
    }
    for (int i = 0; i < M; i++) {
        cin >> P[i].second;
        sum += P[i].second;
    }
    sort(P.begin(), P.end());

    if (sum != N) {
        cout << -1 << endl;
        return;
    }

    ll ans = 0;
    sum = 0;
    for (int i = M-1; i >= 0; i--) {
        ll x = P[i].first, a = P[i].second;
        ll left = N-1-sum-a+1, right = N-1-sum;
        if (x <= left) {
            ans += (left + right - 2*x)*(right - left + 1) / 2;
        } else {
            cout << -1 << endl;
            return;
        }
        sum += a;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
