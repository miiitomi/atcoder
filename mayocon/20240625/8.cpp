// https://atcoder.jp/contests/abc263/tasks/abc263_g
#include <bits/stdc++.h>
#include <atcoder/mincostflow>
using namespace std;
using namespace atcoder;
using ll = long long;

bool is_prime(ll X) {
    for (ll x = 2; x*x <= X; x++) {
        if (X % x == 0) return false;
    }
    return true;
}


void solve() {
    ll N;
    cin >> N;
    vector<pair<ll,ll>> Even, Odd, One;
    for (int i = 0; i < N; i++) {
        pair<ll,ll> p;
        cin >> p.first >> p.second;
        if (p.first % 2 == 0) Even.push_back(p);
        else Odd.push_back(p);
    }

    int num_edges = 2 + Even.size() + Odd.size() + 2*(ll)(One.size() >= 1);
    int s = num_edges-2, t = num_edges-1;

    mcf_graph<ll, ll> mcfg(num_edges);

    for (int i = 0; i < (int)Even.size(); i++) mcfg.add_edge(s, i, Even[i].second, 0);
    for (int i = 0; i < (int)Odd.size(); i++) mcfg.add_edge(Even.size() + i, t, Odd[i].second, (ll)(Odd[i].first == 1LL));

    for (int i = 0; i < (int)Even.size(); i++) {
        pair<ll,ll> &e = Even[i];
        for (int j = 0; j < (int)Odd.size(); j++) {
            pair<ll,ll> &o = Odd[j];
            if (!is_prime(e.first + o.first)) continue;
            ll m = min(e.second, o.second);
            mcfg.add_edge(i, Even.size()+j, m, 0);
        }
    }

    pair<ll,ll> res = mcfg.flow(s, t);
    ll ans = res.first;
    ll m = 0;
    for (auto &o : Odd) if (o.first == 1LL) m += o.second;
    m -= res.second;
    ans += m/2;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
