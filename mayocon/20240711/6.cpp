// https://atcoder.jp/contests/abc253/tasks/abc253_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;
const ll B = 1000;

void solve() {
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<ll>> Queries(Q, vector<ll>(4, -1));
    ll R = (Q+B-1)/B;
    vector<vector<ll>> V(R, vector<ll>(M+1, 0));
    for (int q = 0; q < Q; q++) {
        vector<ll> &v = Queries[q];
        cin >> v[0] >> v[1] >> v[2];
        if (v[0] == 1) {
            cin >> v[3];
            v[1]--; v[2]--;
            int r = q/B;
            V[r][v[1]] += v[3]; V[r][v[2]+1] -= v[3];
        } else if (v[0] == 2) {
            v[1]--;
        } else {
            v[1]--; v[2]--;
        }
    }

    for (int r = 0; r < R; r++) {
        for (int k = 0; k < M; k++) V[r][k+1] += V[r][k];
    }

    vector<pair<ll,ll>> tmp(N, {0, 0});

    for (int q = 0; q < Q; q++) {
        if (Queries[q][0] == 1) continue;
        else if (Queries[q][0] == 2) tmp[Queries[q][1]] = {Queries[q][2], q+1};
        else {
            int i = Queries[q][1], j = Queries[q][2];
            ll ans = tmp[i].first, p = tmp[i].second;
            while (p < q) {
                if (p % B || p+B > q) {
                    if (Queries[p][0] == 1 && Queries[p][1] <= j && j <= Queries[p][2]) ans += Queries[p][3];
                    p++;
                } else {
                    ans += V[p/B][j];
                    p += B;
                }
            }
            cout << ans << "\n";
        }
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
