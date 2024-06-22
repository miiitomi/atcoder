#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    vector<ll> ans(N+1, 0);
    set<ll> done;
    done.insert(0);
    priority_queue<pair<ll,ll>> Q;
    for (int i = 0; i < N; i++) Q.push(make_pair(H[i], i+1));
    while (!Q.empty()) {
        pair<ll,ll> p = Q.top();
        Q.pop();
        auto iter = done.lower_bound(p.second);
        iter--;
        ll i = *iter;
        ans[p.second] =  ans[i] + (p.second-i)*p.first;
        done.insert(p.second);
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i]+1;
        if (i == N) cout << "\n";
        else cout << " ";
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
