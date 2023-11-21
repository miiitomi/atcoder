// https://atcoder.jp/contests/abc173/tasks/abc173_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<vector<ll>> G(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u > v) swap(u, v);
        G[v].push_back(u);
    }

    vector<ll> S(N, 0);
    S[0] = 1;
    for (int i = 1; i < N; i++) {
        S[i] = S[i-1] + i + 1;
        while (!G[i].empty()) {
            S[i] -= G[i].back() + 1;
            G[i].pop_back();
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) ans += S[i];
    cout << ans << endl;

}
