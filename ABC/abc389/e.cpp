#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];

    ll left = 0, right = 4e+18;
    while (right - left > 1) {
        ll tmp = 0;
        ll m = (left + right) / 2;
        for (int i = 0; i < N && tmp <= M; i++) {
            ll k = (m + P[i])/(2*P[i]);
            if (k > (ll)1e+9 || k*k > M/P[i] + 1) {
                tmp = INF;
                break;
            }
            tmp += k*k*P[i];
        }
        if (tmp <= M) left = m;
        else right = m;
    }
    ll m = left;
    vector<ll> cnt(N, 0);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q;
    for (int i = 0; i < N; i++) {
        ll k = (m + P[i])/(2*P[i]);
        cnt[i] = k;
        M -= k*k*P[i];
        Q.push({(2*k+1)*P[i], i});
    }

    while (M >= Q.top().first) {
        M -= Q.top().first;
        cnt[Q.top().second]++;
        ll i = Q.top().second;
        Q.pop();
        Q.push({(2*cnt[i]+1)*P[i], i});
    }
    ll ans = 0;
    for (ll x : cnt) ans += x;
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
