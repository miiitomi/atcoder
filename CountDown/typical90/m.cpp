#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
vector<vector<pair<int, ll>>> G;

vector<ll> f(int s) {
    vector<ll> d(N, 1e+18);
    d[s] =0;
    priority_queue<pair<ll, ll>> Q;
    Q.push(make_pair(0, s));
    
    while (!Q.empty()) {
        auto p = Q.top();
        Q.pop();
        if (-p.first != d[p.second]) continue;
        
        for (auto q : G[p.second]) {
            if (d[q.first] > d[p.second] + q.second) {
                d[q.first] = d[p.second] + q.second;
                Q.push(make_pair(-d[q.first],q.first));
            }
        }
    }
    return d;
}

int main() {
    cin >> N >> M;
    G.resize(N);
    for (int i=0; i<M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    
    vector<ll> d=f(0);
    vector<ll> e=f(N-1);
    
    for (int k=0; k<N; k++) {
        cout << d[k]+e[k] << endl;
    }
}
