#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

struct Train {
    int idx;
    int from;
    int to;
    ll start;
    ll arrive;
    ll x;

    Train(int i, int f, int t, ll s, ll a) {
        idx = i;
        from = f;
        to = t;
        start = s;
        arrive = a;
        x = 0;
    }
};

bool cmp(const Train &l, const Train &r) {
    return l.start < r.start;
}

bool cmp2(const Train &l, const Train &r) {
    return l.idx < r.idx;
}

void solve() {
    ll N, M, X0;
    cin >> N >> M >> X0;
    vector<Train> V;
    for (int i = 0; i < M; i++) {
        ll a, b, s, t;
        cin >> a >> b >> s >> t;
        a--; b--;
        V.push_back(Train(i, a, b, s, t));
        if (i == 0) V.back().x = X0;
    }
    sort(V.begin(), V.end(), cmp);
    vector<ll> Y(N, 0);
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> Q;
    for (Train &train : V) {
        while (!Q.empty() && Q.top()[0] <= train.start) {
            vector<ll> v = Q.top();
            Q.pop();
            Y[v[1]] = max(Y[v[1]], v[2]);
        }
        if (train.start + train.x < Y[train.from]) {
            train.x = Y[train.from] - train.start;
        }
        Q.push({train.arrive, train.to, train.arrive+train.x});
    }
    sort(V.begin(), V.end(), cmp2);
    for (int i = 1; i < (int)V.size(); i++) {
        cout << V[i].x << " ";
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
