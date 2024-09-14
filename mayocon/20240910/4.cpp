// https://atcoder.jp/contests/abc346/tasks/abc346_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    string S;
    cin >> N >> S;
    vector<ll> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];

    vector<vector<ll>> ldp(N, vector<ll>(2, INF)), rdp(N, vector<ll>(2, INF));
    if (S[0] == '0') ldp[0] = {0, C[0]};
    else ldp[0] = {C[0], 0};
    if (S[N-1] == '0') rdp[N-1] = {0, C[N-1]};
    else rdp[N-1] = {C[N-1], 0};

    for (int i = 1; i < N; i++) {
        if (S[i] == '0') {
            ldp[i] = {ldp[i-1][1], ldp[i-1][0]+C[i]};
        } else {
            ldp[i] = {ldp[i-1][1] + C[i], ldp[i-1][0]};
        }
    }

    for (int i = N-2; i >= 0; i--) {
        if (S[i] == '0') {
            rdp[i] = {rdp[i+1][1], rdp[i+1][0]+C[i]};
        } else {
            rdp[i] = {rdp[i+1][1] + C[i], rdp[i+1][0]};
        }
    }

    ll ans = INF;
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < 2; j++) {
            ans = min(ldp[i][j]+rdp[i+1][j], ans);
        }
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
