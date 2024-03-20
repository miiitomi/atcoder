#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void chopt(pair<ll, ll> &p, pair<ll, ll> q) {
    if (p.first > q.first || (p.first == q.first && p.second < q.second)) p = q;
}

void solve() {
    int N;
    cin >> N;
    vector<ll> v;
    vector<vector<ll>> P(N, vector<ll>(N)), R(N, vector<ll>(N-1)), D(N-1, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> P[i][j];
            v.push_back(P[i][j]);
        }
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < N-1; j++) cin >> R[i][j];
    for (int i = 0; i < N-1; i++) for (int j = 0; j < N; j++) cin >> D[i][j];
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int M = v.size();
    unordered_map<ll, int> mp;
    for (int j = 0; j < M; j++) mp[v[j]] = j;

    vector<vector<vector<pair<ll,ll>>>> dp(N, vector<vector<pair<ll,ll>>>(N, vector<pair<ll,ll>>(M, make_pair(INF, -INF))));
    dp[0][0][mp[P[0][0]]] = make_pair(0, 0);
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            for (int k = 0; k < M; k++) {
                if (dp[x][y][k].first == INF) continue;
                ll p = v[k], c = dp[x][y][k].first, e = dp[x][y][k].second;
                if (y+1 <= N-1) {
                    pair<ll,ll> q = make_pair(c+1, e - R[x][y]);
                    if (e < R[x][y]) {
                        ll cnt = (R[x][y] - e + p-1) / p;
                        q.first += cnt;
                        q.second += cnt * p;
                    }
                    chopt(dp[x][y+1][mp[max(p, P[x][y+1])]], q);
                }
                if (x+1 <= N-1) {
                    pair<ll, ll> q = make_pair(c+1, e - D[x][y]);
                    if (e < D[x][y]) {
                        ll cnt = (D[x][y] - e + p-1) / p;
                        q.first += cnt;
                        q.second += cnt * p;
                    }
                    chopt(dp[x+1][y][mp[max(p, P[x+1][y])]], q);
                }
            }
        }
    }

    ll ans = INF;
    for (int k = 0; k < M; k++) ans = min(ans, dp[N-1][N-1][k].first);

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
