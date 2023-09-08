// https://atcoder.jp/contests/abc152/tasks/abc152_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll _pow(ll a, ll n) {
    if (n == 0) return 1;
    ll res = _pow(a, n/2);
    if (n % 2 == 1) return res * res * a;
    else return res * res;
}

bool dfs(int v, int to, int from, vector<vector<pair<int,int>>> &G, vector<int> &E) {
    for (auto p : G[v]) {
        int w = p.first;
        if (w == from) continue;
        else if (w == to) {
            E.push_back(p.second);
            return true;
        } else {
            E.push_back(p.second);
            bool done = dfs(w, to, v, G, E);
            if (done) return true;
            else E.pop_back();
        }
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
    vector<vector<int>> E(M);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        dfs(u, v, -1, G, E[i]);
    }

    ll ng = 0;
    for (int s = 1; s <= (1 << M); s++) {
        set<int> S;
        int cnt = 0;
        for (int k = 0; k < M; k++) {
            if (s & (1 << k)) {
                for (int e : E[k]) S.insert(e);
                cnt++;
            }
        }
        ll a = (ll)S.size();
        if (cnt == 0) continue;
        else if (cnt % 2 == 1) ng += _pow(2, N-1-a);
        else ng -= _pow(2, N-1-a);
    }

    cout << _pow(2, N-1) - ng << endl;
}
