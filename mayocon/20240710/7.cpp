// https://atcoder.jp/contests/abc258/tasks/abc258_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 4e+18;
const ll MOD = 998244353;

ll B, K;

vector<ll> g(ll x) {
    vector<ll> v;
    if (x % B == 0) v.push_back(x);
    else {
        ll r = x % B;
        v.push_back(x-r);
        v.push_back(x+B-r);
    }
    return v;
}

vector<pair<ll,ll>> f(pair<ll,ll> &p) {
    vector<ll> vx = g(p.first), vy = g(p.second);
    vector<pair<ll,ll>> v;
    for (ll x : vx) v.push_back({x, p.second});
    for (ll y : vy) v.push_back({p.first, y});
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

vector<pair<ll,ll>> h(pair<ll,ll> &p) {
    vector<ll> vx = g(p.first), vy = g(p.second);
    vector<pair<ll,ll>> v;
    for (ll x : vx) for (ll y : vy) v.push_back({x, y});
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

ll d(pair<ll,ll> p, pair<ll,ll> q) {
    return abs(p.first-q.first)+abs(p.second-q.second);
}

ll d2(pair<ll,ll> p, pair<ll,ll> q) {
    if (p.first == q.first && p.first%B == 0) return d(p, q);
    if (p.second == q.second && p.second%B == 0) return d(p, q);

    vector<pair<ll,ll>> vp = h(p), vq = h(q);
    ll ans = INF;
    for (auto a : vp) {
        for (auto b: vq) {
            ll tmp = d(a, p) + d(a, b) + d(b, q);
            ans = min(ans, tmp);
        }
    }
    return ans;
}

void solve() {
    cin >> B >> K;
    pair<ll,ll> s, t;
    cin >> s.first >> s.second >> t.first >> t.second;
    ll ans = d(s, t)*K;
    vector<pair<ll,ll>> vs = f(s), vt = f(t);

    for (pair<ll,ll> a : vs) {
        for (pair<ll,ll> b : vt) {
            ll tmp = d(s, a)*K + d2(a, b) + d(b, t)*K;
            ans = min(ans, tmp);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
