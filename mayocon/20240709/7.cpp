// https://atcoder.jp/contests/abc286/tasks/abc286_h
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> vector<pair<T,T>> convex_hull(vector<pair<T,T>> P) {
    // Return ConvecHull of the set of points P via Graham's scan algorithm
    auto pair_minus = [](pair<T,T> p, pair<T,T> q) -> pair<T,T> {return make_pair(p.first - q.first, p.second - q.second);};
    auto cross_product = [](pair<T,T> p, pair<T, T> q) -> T {return p.first*q.second - p.second*q.first;};
    sort(P.begin(), P.end());
    vector<pair<T,T>> Q_over={P[0],P[1]}, Q_under={P[0],P[1]};
    for (int i = 2; i < (int)P.size(); i++) {
        while ((int)Q_over.size() >= 2 && cross_product(pair_minus(P[i], Q_over.back()), pair_minus(Q_over[(int)Q_over.size()-2], Q_over.back())) >= 0) Q_over.pop_back();
        Q_over.push_back(P[i]);
        while ((int)Q_under.size() >= 2 && cross_product(pair_minus(P[i], Q_under.back()), pair_minus(Q_under[(int)Q_under.size()-2], Q_under.back())) <= 0) Q_under.pop_back();
        Q_under.push_back(P[i]);
    }
    vector<pair<T,T>> Q = Q_under;
    for (int i = Q_over.size()-2; i > 0; i--) Q.push_back(Q_over[i]);
    return Q;
}

double dist(pair<ll,ll> &p, pair<ll,ll> &q) {
    return sqrt((p.first-q.first)*(p.first-q.first)+(p.second-q.second)*(p.second-q.second));
}

void solve() {
    ll N;
    cin >> N;
    vector<pair<ll,ll>> Z(N);
    for (int i = 0; i < N; i++) cin >> Z[i].first >> Z[i].second;
    pair<ll,ll> s, t;
    cin >> s.first >> s.second >> t.first >> t.second;
    Z.push_back(s); Z.push_back(t);
    sort(Z.begin(), Z.end());
    vector<pair<ll,ll>> CH = convex_hull(Z);

    auto iter1 = find(CH.begin(), CH.end(), s);
    auto iter2 = find(CH.begin(), CH.end(), t);
    if (iter1 == CH.end() || iter2 == CH.end()) {
        cout << dist(s, t) << endl;
        return;
    }

    bool was_s = (CH[0] == s); bool was_t = (CH[0] == t);
    double ans = INF;
    double tmp = 0;
    int M = CH.size();
    for (int i = 1; i <= 2*M; i++) {
        tmp += dist(CH[(i-1)%M], CH[i%M]);
        if (CH[i%M] == s) {
            if (was_t) ans = min(ans, tmp);
            was_t = false;
            was_s = true;
            tmp = 0;
        }
        if (CH[i%M] == t) {
            if (was_s) ans = min(ans, tmp);
            was_s = false;
            was_t = true;
            tmp = 0;
        }
    }
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
