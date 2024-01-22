// https://atcoder.jp/contests/abc325/tasks/abc325_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    deque<pair<ll, ll>> V(N);
    for (int i = 0; i < N; i++) cin >> V[i].first >> V[i].second;
    sort(V.begin(), V.end());

    ll cnt = 0;
    priority_queue<ll, vector<ll>, greater<ll>> Q;
    while (!V.empty()) {
        ll t = V.front().first;
        ll x = t + V.front().second;
        Q.push(x);
        V.pop_front();
        ll nt = 2e+18;
        if (!V.empty()) nt = V.front().first;
        while (t < nt && !Q.empty()) {
            ll p = Q.top();
            Q.pop();
            if (p < t) continue;
            cnt++;
            t++;
        }
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
