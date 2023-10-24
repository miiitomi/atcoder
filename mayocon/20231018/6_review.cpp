// https://atcoder.jp/contests/abc314/tasks/abc314_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll modinv(ll a) {
    // Check if a and MOD are coprime.
    ll b = MOD, u = 1, v = 0;
    while (b > 0) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

int main() {
    int N;
    cin >> N;
    vector<ll> E(N, 0);
    vector<int> par(N, -1), num(N, 1);
    vector<vector<int>> child(N);

    for (int t = 0; t < N-1; t++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        vector<int> P;
        while (par[u] != -1) {
            P.push_back(u);
            u = par[u];
        }
        while (!P.empty()) {
            par[P.back()] = u;
            P.pop_back();
        }
        while (par[v] != -1) {
            P.push_back(v);
            v = par[v];
        }
        while (!P.empty()) {
            par[P.back()] = v;
            P.pop_back();
        }

        ll inv = modinv(num[u] + num[v]);
        E[u] = (num[u] * inv) % MOD;
        E[v] = (num[v] * inv) % MOD;

        E.push_back(0);
        par.push_back(-1);
        child.push_back({u, v});
        num.push_back(num[u]+num[v]);
        par[u] = (int)par.size() - 1;
        par[v] = (int)par.size() - 1;
    }

    for (int u = (int)E.size()-1; u >= N; u--) {
        for (int c : child[u]) {
            E[c] = (E[c] + E[u]) % MOD;
        }
    }

    for (int u = 0; u < N; u++) cout << E[u] << " ";
    cout << endl;
}
