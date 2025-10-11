#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

void solve() {
    vector<ll> P(6);
    for (int i = 0; i < 6; i++) cin >> P[i];
    vector<ll> Q = {1, 5, 10, 50, 100, 500};
    ll N;
    cin >> N;
    priority_queue<ll> PQ;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        PQ.push(x);
    }

    for (int i = 5; i >= 0; i--) {
        while (P[i] > 0 && !PQ.empty() && PQ.top() >= Q[i]) {
            ll x = PQ.top();
            PQ.pop();
            x -= Q[i];
            P[i]--;
            if (x > 0) PQ.push(x);
        }
    }

    if (PQ.empty()) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
