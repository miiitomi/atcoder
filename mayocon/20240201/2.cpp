// https://atcoder.jp/contests/abc214/tasks/abc214_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll INF = 1e+18;

void solve() {
    ll N;
    cin >> N;
    vector<ll> S(N), T(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < N; i++) cin >> T[i];

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q;
    for (int i = 0; i < N; i++) Q.push(make_pair(T[i], i));

    vector<ll> dp(N, INF);
    ll cnt = 0;
    while (cnt < N) {
        pair<ll, ll> p = Q.top();
        Q.pop();
        int i = p.second;
        ll d = p.first;
        if (dp[i] < INF) continue;
        dp[i] = d;
        cnt++;
        if (dp[(i+1)%N] == INF) Q.push(make_pair(d + S[i], (i+1)%N));
    }

    for (int i = 0; i < N; i++) cout << dp[i] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
