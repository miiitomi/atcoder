#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> struct Fenwick {
    int n;
    vector<T> data;
    T sum = 0;

    Fenwick(int _n) {
        n = _n + 1;
        data.assign(n, 0);
        sum = 0;
    }

    Fenwick() {
        Fenwick(0);
    }

    void add(int i, T x) {
        // Add x to a[i] (0-indexed).
        for (int idx = i + 1; idx < n; idx += (idx & -idx)) {
            data[idx] += x;
        }
        sum += x;
    }

    T _sum(int i) {
        // compute sum of a[k] for k in [0, i)
        T ans = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            ans += data[idx];
        }
        return ans;
    }

    T query(int a, int b) {
        // compute sum of a[k] for k in [a, b)
        return _sum(b) - _sum(a);
    }
};

vector<ll> A, B, v;
Fenwick<ll> FA, GA, FB, GB;

constexpr int maxn = 1 << 20;
ll hilbertorder(int x, int y) {
  ll rx, ry, d = 0;
  for (ll s=maxn>>1; s; s>>=1) {
    rx = (x & s)>0, ry = (y & s)>0;
    d += s * s * ((rx * 3) ^ ry);
    if (ry) continue;
    if (rx) {
      x = maxn-1 - x;
      y = maxn-1 - y;
    }
    swap(x, y);
  }
  return d;
}


template <typename T>
struct Mo {
    struct Query {
        int id, l, r, l_;
        Query(int i, int l, int r, int b = 1): id(i), l(l), r(r) {l_ = l / b;}
    };

    int N, Q, bbb;
    vector<Query> queries;
    vector<T> ans;
    int left=0, right=0;

    /* Update below! */
    vector<T> state;    // TODO: Set state variables.
    T tmp = 0;    // TODO: Set initial tmp answer.

    void _query(Query &q) {
        while (left < q.l) {
            ll a = A[left];
            pair<ll,ll> res = {FB.query(0, a), GB.query(0, a)};
            tmp += res.second*v[a] - res.first;
            res = {FB.sum-res.first, GB.sum-res.second};
            tmp += res.first - res.second*v[a];
            FA.add(a, v[a]);
            GA.add(a, 1);
            left++;
        }
        while (right < q.r) {
            ll b = B[right];
            pair<ll,ll> res = {FA.query(0, b), GA.query(0, b)};
            tmp += res.second*v[b] - res.first;
            res = {FA.sum - res.first, GA.sum - res.second};
            tmp += res.first - res.second*v[b];
            FB.add(b, v[b]);
            GB.add(b, 1);
            right++;
        }
        while (q.l < left) {
            left--;
            ll a = A[left];
            pair<ll,ll> res = {FB.query(0, a), GB.query(0, a)};
            tmp -= res.second*v[a] - res.first;
            res = {FB.sum-res.first, GB.sum-res.second};
            tmp -= res.first - res.second*v[a];
            FA.add(a, -v[a]);
            GA.add(a, -1);
        }
        while (q.r < right) {
            right--;
            ll b = B[right];
            pair<ll,ll> res = {FA.query(0, b), GA.query(0, b)};
            tmp -= res.second*v[b] - res.first;
            res = {FA.sum - res.first, GA.sum - res.second};
            tmp -= res.first - res.second*v[b];
            FB.add(b, -v[b]);
            GB.add(b, -1);
        }
        ans[q.id] = tmp;
    }
    Mo(int n, int q): N(n), Q(q) {
        bbb = 500;
        queries.assign(Q, {0, 0, 0});
        ans.assign(Q, 0);
        state.assign(N, 0);  // TODO: Set state variable.
    }
    /* Up to here! */

    void add_query(int i, int l, int r) {
        // Add i'th query for [l, r] . (REMARK: closed interval!)
        queries[i] = Query(i, l, r, bbb);
    }

    void run() {
        sort(queries.begin(), queries.end(), [](Query &q1, Query &q2){
            return hilbertorder(q1.l, q1.r) < hilbertorder(q2.l, q2.r);
        });
        for (Query &q : queries) _query(q);
    }
};

void solve() {
    ll N;
    cin >> N;
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        v.push_back(A[i]);
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        v.push_back(B[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (ll &a : A) a = distance(v.begin(), lower_bound(v.begin(), v.end(), a));
    for (ll &b : B) b = distance(v.begin(), lower_bound(v.begin(), v.end(), b));
    FA = Fenwick<ll>(v.size());
    FB = Fenwick<ll>(v.size());
    GA = Fenwick<ll>(v.size());
    GB = Fenwick<ll>(v.size());

    ll K;
    cin >> K;
    Mo<ll> mo(N, K);
    for (int i = 0; i < K; i++) {
        ll x, y;
        cin >> x >> y;
        mo.add_query(i, x, y);
    }
    mo.run();

    for (ll v : mo.ans) {
        cout << v << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
