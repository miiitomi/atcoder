#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, L;
    cin >> N >> L;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    while (N--) {
        ll a;
        cin >> a;
        pq.push(a);
        L -= a;
    }
    if (L > 0) pq.push(L);
    ll ans = 0;
    while (pq.size() >= 2) {
        ll a = pq.top();
        pq.pop();
        a += pq.top();
        pq.pop();
        ans += a;
        pq.push(a);
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
