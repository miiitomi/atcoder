// https://atcoder.jp/contests/abc273/tasks/abc273_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;
template<typename T> bool chmin(T &v, T nv) {
    if (v > nv) {
        v = nv;
        return true;
    }
    return false;
}

void solve() {
    ll N, G, S = 0;
    cin >> N >> G;
    vector<ll> v{S, G}, Y(N), Z(N);
    for (int i = 0; i < N; i++) {
        cin >> Y[i];
        v.push_back(Y[i]);
    }
    for (int i = 0; i < N; i++) {
        cin >> Z[i];
        v.push_back(Z[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    S = distance(v.begin(), lower_bound(v.begin(), v.end(), S));
    G = distance(v.begin(), lower_bound(v.begin(), v.end(), G));
    for (ll &y : Y) y = distance(v.begin(), lower_bound(v.begin(), v.end(), y));
    for (ll &z : Z) z = distance(v.begin(), lower_bound(v.begin(), v.end(), z));
    vector<pair<char, int>> T(v.size());
    T[S] = {'S', 0};
    T[G] = {'G', 0};
    for (int i = 0; i < N; i++) {
        T[Y[i]] = {'W', i};
        T[Z[i]] = {'H', i};
    }
    vector<vector<vector<ll>>> dp(v.size(), vector<vector<ll>>(v.size(), {INF, INF}));
    dp[S][S] = {0, 0};
    priority_queue<tuple<ll,ll,ll,int>, vector<tuple<ll,ll,ll,int>>, greater<tuple<ll,ll,ll,int>>> Q;
    Q.push({0, S, S, 0});
    ll ans = INF;
    while (!Q.empty()) {
        auto [val, L, R, k] = Q.top();
        Q.pop();
        if (val != dp[L][R][k]) continue;
        if (R+1 < (int)v.size()) {
            ll d = dp[L][R][k] + v[R+1] - v[L*(1-k)+R*k];
            if (T[R+1].first != 'W' || (T[R+1].first == 'W' && L <= Z[T[R+1].second] && Z[T[R+1].second] <= R)) {
                if (chmin(dp[L][R+1][1], d)) {
                    Q.push({d, L, R+1, 1});
                    if (T[R+1].first == 'G') chmin(ans, d);
                }
            }
        }
        if (L-1 >= 0) {
            ll d = dp[L][R][k] + v[L*(1-k)+R*k] - v[L-1];
            if (T[L-1].first != 'W' || (T[L-1].first == 'W' &&  L <= Z[T[L-1].second] && Z[T[L-1].second] <= R)) {
                if (chmin(dp[L-1][R][0], d)) {
                    Q.push({d, L-1, R, 0});
                    if (T[L-1].first == 'G') chmin(ans, d);
                }
            }
        }
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
