#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

struct Query {
    ll l, r, i, ans;
};

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll,ll>> edges(M);
    for (int i = 0; i < M; i++) cin >> edges[i].first >> edges[i].second;
    sort(edges.begin(), edges.end());

    ll Q;
    cin >> Q;
    vector<Query> queries(Q);
    for (int q = 0; q < Q; q++) {
        queries[q].i = q;
        queries[q].ans = 0;
        cin >> queries[q].l >> queries[q].r;
    }
    sort(queries.begin(), queries.end(), [](const auto &l, const auto &r) {return l.l < r.l;});

    fenwick_tree<ll> R(2*N+1);
    int i = 0;
    for (auto &q: queries) {
        while (i < M && edges[i].first < q.l) {
            R.add(edges[i].second, 1);
            i++;
        }
        q.ans += R.sum(q.l, q.r);
    }

    for (auto &e: edges) {
        e.first = 2*N+1 - e.first;
        e.second = 2*N+1 - e.second;
        swap(e.first, e.second);
    }
    for (auto &q: queries) {
        q.l = 2*N+1 - q.l;
        q.r = 2*N+1 - q.r;
        swap(q.l, q.r);
    }
    sort(edges.begin(), edges.end());
    sort(queries.begin(), queries.end(), [](const auto &l, const auto &r) {return l.l < r.l;});

    R = fenwick_tree<ll>(2*N+1);
    i = 0;
    for (auto &q: queries) {
        while (i < M && edges[i].first < q.l) {
            R.add(edges[i].second, 1);
            i++;
        }
        q.ans += R.sum(q.l, q.r);
    }

    sort(queries.begin(), queries.end(), [](const auto &l, const auto &r) {return l.i < r.i;});

    for (auto &q: queries) cout << q.ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
