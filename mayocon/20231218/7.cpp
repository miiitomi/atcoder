// https://atcoder.jp/contests/abc307/tasks/abc307_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M, K, D;
    cin >> N >> M;
    vector<vector<pair<int, ll>>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u-1].push_back(make_pair(v-1, w));
        G[v-1].push_back(make_pair(u-1, w));
    }
    cin >> K;
    vector<int> A(K);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
        A[i]--;
    }
    cin >> D;
    vector<ll> X(D+1, 0);
    for (int i = 1; i <= D; i++) cin >> X[i];

    vector<ll> d(N, 1e+18), ans(N, 1e+18);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> E;
    for (int a : A) {
        ans[a] = 0;
        d[a] = 0;
        for (auto &p : G[a]) {
            E.push(make_pair(p.second, p.first));
        }
    }

    for (int s = 1; s <= D; s++) {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
        while (!E.empty() && E.top().first <= X[s]) {
            ll u = E.top().second, w = E.top().first;
            E.pop();
            if (ans[u] < s || d[u] <= w) continue;
            ans[u] = s;
            d[u] = w;
            Q.push(make_pair(w, u));
        }

        while (!Q.empty()) {
            ll u = Q.top().second, dist = Q.top().first;
            Q.pop();
            if (d[u] != dist) continue;
            for (auto &e : G[u]) {
                ll v = e.first, c = e.second;
                if (ans[v] < s || d[v] <= d[u] + c) continue;
                if (d[u] + c <= X[s]) {
                    d[v] = d[u] + c;
                    ans[v] = s;
                    Q.push(make_pair(d[v], v));
                } else {
                    E.push(make_pair(c, v));
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (ans[i] <= D) cout << ans[i] << endl;
        else cout << -1 << endl;
    }
}
