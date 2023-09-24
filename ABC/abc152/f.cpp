#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll _pow(ll a, ll n) {
    if (n == 0) return 1;
    ll res = _pow(a, n/2);
    if (n % 2 == 1) return res * res * a;
    else return res * res;
}

bool dfs(int v, int f, int g, vector<vector<pair<int,int>>> &G, vector<int> &path) {
    for (auto p : G[v]) {
        int w = p.first;
        int i = p.second;
        if (w == f) continue;
        if (w == g) {
            path.push_back(i);
            return true;
        }
        path.push_back(i);
        bool res = dfs(w, v, g, G, path);
        if (res) return true;
        else path.pop_back();
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<vector<pair<int,int>>> G(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(make_pair(b, i));
        G[b].push_back(make_pair(a, i));
    }

    int M;
    cin >> M;
    vector<int> u(M), v(M);
    vector<vector<int>> Edges(M);
    for (int i = 0; i < M; i++) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
        dfs(u[i], -1, v[i], G, Edges[i]);
    }

    ll ng = 0;
    for (int s = 1; s < (1 << M); s++) {
        int cnt = 0;
        unordered_set<int> sint;
        for (int k = 0; k < M; k++) {
            if (s & (1 << k)) {
                cnt++;
                for (int i : Edges[k]) sint.insert(i);
            }
        }
        ll c = sint.size();
        if (cnt % 2 == 1) ng += _pow(2LL, N-1-c);
        else ng -= _pow(2LL, N-1-c);
    }

    ll ans = _pow(2, N-1) - ng;
    cout << ans << endl;
}
