// https://atcoder.jp/contests/abc277/tasks/abc277_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

struct UnionFind {
    vector<int> par, siz;

    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

void solve() {
    ll sum = 0;
    ll N, M;
    cin >> N >> M;
    map<ll, vector<ll>> mp;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        mp[a%M].push_back(a);
        sum += a;
    }
    vector<ll> V, summ;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        V.push_back(iter->first);
        ll tmp = 0;
        for (auto x : iter->second) tmp += x;
        summ.push_back(tmp);
    }
    UnionFind uf(V.size());
    for (int i = 0; i < (int)V.size(); i++) {
        if (i != (int)V.size()-1) {
            if (V[i+1] == V[i]+1) uf.unite(i, i+1);
        } else {
            if (V[i] == M-1 && V[0] == 0) uf.unite(i, 0);
        }
    }
    vector<ll> ans(V.size(), sum);
    for (int i = 0; i < (int)V.size(); i++) {
        int r = uf.root(i);
        ans[r] -= summ[i];
    }
    cout << *min_element(ans.begin(), ans.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
