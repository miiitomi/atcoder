#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> P(N);
    vector<pair<ll, ll>> Q(M);
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < M; i++) cin >> Q[i].first;
    for (int i = 0; i < M; i++) cin >> Q[i].second;
    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());
    reverse(Q.begin(), Q.end());

    priority_queue<ll, vector<ll>, greater<ll>> que;
    for (int i = 0; i < M; i++) {
        ll l = Q[i].first;
        ll d = Q[i].second;
        auto iter = lower_bound(P.begin(), P.end(), l);
        if ((int)que.size() >= (int)distance(iter, P.end())) {
            if (!que.empty() && que.top() < d) {
                que.pop();
                que.push(d);
            } else {
                continue;
            }
        } else {
            que.push(d);
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) ans += P[i];
    while (!que.empty()) {
        ll c = que.top();
        que.pop();
        ans -= c;
    }

    cout << ans << endl;
}
