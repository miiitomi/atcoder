// https://atcoder.jp/contests/abc141/tasks/abc141_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;
    priority_queue<pair<ll,ll>> Q;
    vector<ll> A(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        ans += A[i];
        Q.push({A[i]/2+(A[i]%2), i});
    }
    while (M-- && !Q.empty()) {
        auto p = Q.top();
        Q.pop();
        ans -= p.first;
        int i = p.second;
        A[p.second] /= 2;
        if (A[p.second] > 0) Q.push({A[i]/2+(A[i]%2), i});
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
