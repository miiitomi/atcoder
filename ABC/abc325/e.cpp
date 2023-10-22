#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<vector<ll>> D(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> D[i][j];

    vector<ll> d1(N, 1e+18);
    d1[0] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q;
    Q.push(make_pair(0, 0));

    while (!Q.empty()) {
        ll v = Q.top().second;
        ll d = Q.top().first;
        Q.pop();
        if (d != d1[v]) continue;

        for (int i = 0; i < N; i++) {
            if (v == i || d1[i] <= d1[v] + A*D[i][v]) continue;
            d1[i] = d1[v] + A*D[i][v];
            Q.push(make_pair(d1[i], i));
        }
    }

    vector<ll> d2(N, 1e+18);
    d2[N-1] = 0;
    Q.push(make_pair(0, N-1));

    while (!Q.empty()) {
        ll v = Q.top().second;
        ll d = Q.top().first;
        Q.pop();
        if (d != d2[v]) continue;

        for (int i = 0; i < N; i++) {
            if (v == i || d2[i] <= d2[v] + B*D[i][v] + C) continue;
            d2[i] = d2[v] + B*D[i][v] + C;
            Q.push(make_pair(d2[i], i));
        }
    }

    ll ans = 1e+18;
    for (int i = 0; i < N; i++) ans = min(ans, d1[i] + d2[i]);
    cout << ans << endl;
}
