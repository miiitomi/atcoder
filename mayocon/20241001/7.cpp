// https://atcoder.jp/contests/abc368/tasks/abc368_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

struct Train {
    ll from, to, s, t, idx, x = 0;
    Train(ll _from, ll _to, ll _s, ll _t, ll _idx) {
        from = _from;
        to = _to;
        s = _s;
        t = _t;
        idx = _idx;
    }
};

void solve() {
    ll N, M, X;
    cin >> N >> M >> X;
    vector<Train> V;
    for (int i = 0; i < M; i++) {
        ll a, b, s, t;
        cin >> a >> b >> s >> t;
        V.push_back(Train(a-1, b-1, s, t, i));
        if (i == 0) V.back().x = X;
    }
    sort(V.begin(), V.end(), [](const Train &l, const Train &r) {return l.s < r.s;});
    vector<ll> delay(N, 0);
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> Q;
    for (Train &train : V) {
        while (!Q.empty() && Q.top()[0] <= train.s) {
            delay[Q.top()[2]] = max(delay[Q.top()[2]], Q.top()[1]);
            Q.pop();
        }
        if (train.s + train.x < delay[train.from]) train.x = delay[train.from] - train.s;
        Q.push({train.t, train.t + train.x, train.to});
    }
    sort(V.begin(), V.end(), [](const Train &l, const Train &r) {return l.idx < r.idx;});

    for (int i = 1; i < M; i++) {
        cout << V[i].x;
        if (i < M-1) cout << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
