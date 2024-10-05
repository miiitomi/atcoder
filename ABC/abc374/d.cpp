#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

double dist(ll s, ll t, ll a, ll b) {
    return sqrt((s-a)*(s-a) + (t-b)*(t-b) + 0.0);
}

void solve() {
    ll N, S, T;
    cin >> N >> S >> T;
    vector<pair<pair<ll,ll>, pair<ll,ll>>> V(N);
    for (int i = 0; i < N; i++) cin >> V[i].first.first >> V[i].first.second >> V[i].second.first >> V[i].second.second;
    sort(V.begin(), V.end());
    double ans = INF;
    do {
        for (ll s = 0; s < (1 << N); s++) {
            ll x = 0, y = 0;
            double tmp = 0;
            for (int i = 0; i < N; i++) {
                auto p = V[i];
                ll a = p.first.first, b = p.first.second, c = p.second.first, d = p.second.second;
                if (s & (1 << i)) {
                    swap(a, c);
                    swap(b, d);
                }
                tmp += dist(x, y, a, b)/S + dist(a, b, c, d)/T;
                x = c;
                y = d;
            }
            ans = min(ans, tmp);
        }
    } while (next_permutation(V.begin(), V.end()));
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
