#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;
const ll C = 1000;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> cnt(N, 0);
    vector<ll> T(M), P(M);
    vector<vector<ll>> R(N);
    for (int i = 0; i < M; i++) {
        cin >> T[i] >> P[i];
        P[i]--;
        cnt[P[i]]++;
        R[P[i]].push_back(T[i]);
    }
    vector<vector<ll>> cum(N);
    vector<ll> over_c;
    for (int i = 0; i < N; i++) {
        if (cnt[i] >= C) {
            cum[i].assign(M, 0);
            over_c.push_back(i);
        }
    }
    vector<ll> tmp(N, 0);
    for (int i = 0; i < M; i++) {
        if (i > 0) {
            for (int j : over_c) {
                if (tmp[j]) cum[j][i] = cum[j][i-1] + T[i] - T[i-1];
                else cum[j][i] = cum[j][i-1];
            }
        }
        tmp[P[i]] = 1 - tmp[P[i]];
    }
    ll Q;
    cin >> Q;
    vector<ll> A(Q), B(Q), ans(Q, -1);
    vector<vector<pair<ll,ll>>> G(N);
    map<pair<ll,ll>, ll> mp;
    for (int i = 0; i < Q; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        if (cnt[A[i]] > cnt[B[i]]) swap(A[i], B[i]);

        if (mp.count(make_pair(A[i], B[i]))) continue;
        mp[{A[i],B[i]}] = -1;

        if (cnt[B[i]] >= C) {
            G[A[i]].push_back({B[i], i});
            ans[i] = 0;
        }
    }
    tmp.assign(N, -1);
    for (int i = 0; i < M; i++) {
        ll p = P[i];
        if (tmp[p] == -1) tmp[p] = i;
        else {
            for (auto &e : G[p]) ans[e.second] += cum[e.first][i] - cum[e.first][tmp[p]];
            tmp[p] = -1;
        }
    }

    for (ll q = 0; q < Q; q++) {
        if (mp[{A[q], B[q]}] != -1) {
            cout << mp[{A[q], B[q]}] << "\n";
        } else if (ans[q] != -1) {
            cout << ans[q] << "\n";
            mp[{A[q], B[q]}] = ans[q];
        } else {
            ll a = A[q], b = B[q];
            ll ia = 0, ib = 0;
            bool in_a = false, in_b = false;
            ll ans = 0;
            while (ia < cnt[a] && ib < cnt[b]) {
                if (R[a][ia] < R[b][ib]) {
                    if (!in_a) {
                        in_a = true;
                        if (in_b) ans -= R[a][ia]; 
                    } else {
                        in_a = false;
                        if (in_b) ans += R[a][ia];
                    }
                    ia++;
                } else {
                    if (!in_b) {
                        in_b = true;
                        if (in_a) ans -= R[b][ib];
                    } else {
                        in_b = false;
                        if (in_a) ans += R[b][ib];
                    }
                    ib++;
                }
            }
            cout << ans << "\n";
            mp[{A[q], B[q]}] = ans;
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
