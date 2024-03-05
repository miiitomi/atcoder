#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll,ll> vector_minus(pair<ll, ll> p, pair<ll, ll> q) {
    return make_pair(p.first-q.first, p.second-q.second);
}

ll cross_product(pair<ll,ll> p, pair<ll,ll> q) {
    return p.first*q.second - p.second*q.first;
}

void solve() {
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<pair<ll, ll>> P(N+1, {0, 0});
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        P[i+1] = make_pair(i+1, P[i].second + A[i]);
    }
    vector<double> ans(N, 0);
    vector<pair<ll, ll>> Q;
    Q.push_back(P.back());
    for (int i = N-1; i >= 0; i--) {
        while (Q.size() >= 2 && cross_product(vector_minus(P[i], Q.back()), vector_minus(Q[(int)Q.size()-2], Q.back())) < 0) Q.pop_back();
        Q.push_back(P[i]);
        ans[i] = (Q[(int)Q.size()-2].second - Q.back().second + 0.0) / (Q[(int)Q.size()-2].first - Q.back().first + 0.0);
    }
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
