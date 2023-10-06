// https://atcoder.jp/contests/abc267/tasks/abc267_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> C(N, 0);
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
        C[u] += A[v];
        C[v] += A[u];
    }

    unordered_set<int> Done;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> Q;
    for (int i = 0; i < N; i++) Q.push(make_pair(C[i], i));

    ll cost = 0;
    while (Done.size() < N) {
        auto p = Q.top();
        Q.pop();
        if (Done.count(p.second)) continue;
        Done.insert(p.second);
        cost = max(cost, p.first);
        for (int v : G[p.second]) {
            if (!Done.count(v)) {
                C[v] -= A[p.second];
                Q.push(make_pair(C[v], v));
            }
        }
    }

    cout << cost << endl;
}
