// https://atcoder.jp/contests/abc211/tasks/abc211_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

struct Query {
    ll idx, x, y, ans;
    Query(ll i, ll _x, ll _y) {
        idx = i;
        x = _x;
        y = _y;
    }
};

ll op(ll a, ll b) {return a+b;}
ll e() {return 0;}
ll mapping(ll f, ll x) {return x+f;}
ll composition(ll f, ll g) {return f+g;}
ll id() {return 0;}

void solve() {
    ll N;
    cin >> N;
    vector<pair<ll, pair<ll,ll>>> A, B;
    lazy_segtree<ll, op, e, ll, mapping, composition, id> lst((ll)1e+5 + 2);
    for (int i = 0; i < N; i++) {
        ll M;
        cin >> M;
        vector<pair<ll, pair<ll,ll>>> E;
        for (int i = 0; i < M; i += 2) {
            ll x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            E.push_back({x1, {min(y1,y2), max(y1,y2)}});
        }
        sort(E.begin(), E.end());
        for (auto &e : E) {
            int y1 = e.second.first, y2 = e.second.second;
            if (lst.get(y1) == 0) {
                lst.apply(y1, y2, 1);
                A.push_back(e);
            } else {
                lst.apply(y1, y2, -1);
                B.push_back(e);
            }
        }
    }
    ll Q;
    cin >> Q;
    vector<Query> V;
    for (int i = 0; i < Q; i++) {
        ll x, y;
        cin >> x >> y;
        V.push_back(Query(i, x, y));
    }
    sort(V.begin(), V.end(), [](const Query &l, const Query &r) {if (l.x != r.x) return l.x < r.x; return l.y < r.y;});
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    for (auto &v : V) {
        while (!B.empty() && B.back().first <= v.x) {
            lst.apply(B.back().second.first, B.back().second.second, -1);
            B.pop_back();
        }
        while (!A.empty() && A.back().first <= v.x) {
            lst.apply(A.back().second.first, A.back().second.second, 1);
            A.pop_back();
        }
        v.ans = lst.get(v.y);
    }
    sort(V.begin(), V.end(), [](const Query &l, const Query &r) {return l.idx < r.idx;});
    for (auto &v : V) cout << v.ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
