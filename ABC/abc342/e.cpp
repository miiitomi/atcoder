#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 9e+18;

struct Train {
    ll l, d, k, c, from, to;
    Train(ll _l, ll _d, ll _k, ll _c, ll _from, ll _to) {
        l = _l;
        d = _d;
        k = _k;
        c = _c;
        from = _from;
        to = _to;
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<Train>> G(N);
    for (int i = 0; i < M; i++) {
        ll l, d, k, c, a, b;
        cin >> l >> d >> k >> c >> a >> b;
        a--;
        b--;
        G[b].push_back(Train(l, d, k, c, a, b));
    }

    vector<ll> dp(N, -INF);
    dp[N-1] = INF;
    priority_queue<pair<ll, ll>> Q;
    Q.push(make_pair(INF, N-1));

    while (!Q.empty()) {
        ll dist = Q.top().first, u = Q.top().second;
        Q.pop();
        if (dp[u] != dist || dp[u] < 0) continue;

        for (Train &t : G[u]) {
            ll left = 0, right = dp[u];
            while (right - left > 1) {
                ll m = (right + left) / 2;

                if (m > t.l + (t.k - 1)*t.d) {
                    right = m;
                    continue;
                }

                ll s;
                if (m <= t.l) s = t.l;
                else if ((m - t.l) % t.d == 0) s = m;
                else s = m + (t.d - ((m - t.l) % t.d));
                ll g = s + t.c;

                if (g <= dp[u]) left = m;
                else right = m;
            }

            if (left < t.l) continue;
            ll tmp = left;
            if (dp[t.from] < tmp) {
                dp[t.from] = tmp;
                Q.push(make_pair(tmp, t.from));
            }
        }
    }

    for (int i = 0; i < N-1; i++) {
        if (dp[i] > 0) cout << dp[i] << "\n";
        else cout << "Unreachable\n";
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
