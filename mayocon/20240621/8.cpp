// https://atcoder.jp/contests/abc341/tasks/abc341_g
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;

template<typename T> vector<double> convex_hull(vector<pair<T,T>> P) {
    // Return ConvecHull of the set of points P via Graham's scan algorithm
    auto pair_minus = [](pair<T,T> p, pair<T,T> q) -> pair<T,T> {return make_pair(p.first - q.first, p.second - q.second);};
    auto cross_product = [](pair<T,T> p, pair<T, T> q) -> T {return p.first*q.second - p.second*q.first;};
    sort(P.begin(), P.end());
    reverse(P.begin(), P.end());
    vector<pair<T,T>> Q_over={P[0],P[1]};
    vector<double> ans(N, 0.0);
    ans[Q_over[(int)Q_over.size()-1].first] = (Q_over[(int)Q_over.size()-2].second - Q_over[(int)Q_over.size()-1].second) / (0.0 + Q_over[(int)Q_over.size()-2].first - Q_over[(int)Q_over.size()-1].first);
    for (int i = 2; i < (int)P.size(); i++) {
        while ((int)Q_over.size() >= 2 && cross_product(pair_minus(P[i], Q_over.back()), pair_minus(Q_over[(int)Q_over.size()-2], Q_over.back())) <= 0) Q_over.pop_back();
        Q_over.push_back(P[i]);
        ans[Q_over[(int)Q_over.size()-1].first] = (Q_over[(int)Q_over.size()-2].second - Q_over[(int)Q_over.size()-1].second) / (0.0 + Q_over[(int)Q_over.size()-2].first - Q_over[(int)Q_over.size()-1].first);
    }
    return ans;
}

void solve() {
    cin >> N;
    vector<ll> A(N);
    vector<pair<ll,ll>> P{{0,0}};
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
        P.push_back({i+1, sum});
    }
    vector<double> ans = convex_hull(P);
    for (double a : ans) cout << a << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
