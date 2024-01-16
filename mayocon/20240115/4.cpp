// https://atcoder.jp/contests/abc325/tasks/abc325_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<vector<ll>> D(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> D[i][j];
    }

    vector<ll> car(N, 1e+18), train(N, 1e+18);
    car[0] = 0;
    train[N-1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push(make_pair(0, 0));
    while (!Q.empty()) {
        int u = Q.top().second;
        ll d = Q.top().first;
        Q.pop();
        if (car[u] != d) continue;
        for (int w = 0; w < N; w++) {
            if (car[w] > car[u] + A*D[u][w]) {
                car[w] = car[u] + A*D[u][w];
                Q.push(make_pair(car[w], w));
            }
        }
    }
    Q.push(make_pair(train[N-1], N-1));
    while (!Q.empty()) {
        int u = Q.top().second;
        ll d = Q.top().first;
        Q.pop();
        if (train[u] != d) continue;
        for (int w = 0; w < N; w++) {
            if (train[w] > train[u] + B*D[u][w] + C) {
                train[w] = train[u] + B*D[u][w] + C;
                Q.push(make_pair(train[w], w));
            }
        }
    }

    ll ans = min(car[N-1], train[0]);
    for (int u = 1; u < N-1; u++) ans = min(ans, car[u] + train[u]);
    cout << ans << endl;
}
