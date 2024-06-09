#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<pair<ll,ll>> P(N);
    for (int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;
    sort(P.begin(), P.end());
    priority_queue<ll, vector<ll>, greater<ll>> Q;
    ll ans = 0;
    for (auto &p : P) {
        while (!Q.empty() && Q.top() < p.first) Q.pop();
        ans += Q.size();
        Q.push(p.second);
    }
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
