// https://atcoder.jp/contests/abc334/tasks/abc334_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

double d(pair<ll,ll> &p, pair<ll,ll> &q) {
    return sqrt((double)(p.first-q.first)*(p.first-q.first) + (p.second-q.second)*(p.second-q.second));
}

void solve() {
    ll N, K;
    cin >> N >> K;
    pair<ll,ll> S;
    cin >> S.first >> S.second;
    vector<pair<ll,ll>> P(N);
    for (int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;
    deque<double> D(K, 0);
    multiset<double> st;
    for (int k = 0; k < K; k++) st.insert(0);
    for (int i = 1; i < N; i++) {
        double m = *st.begin();
        st.erase(st.find(D.front()));
        D.pop_front();
        D.push_back(m + d(P[i-1], S)+d(S, P[i])-d(P[i-1], P[i]));
        st.insert(D.back());
    }

    double ans = *st.begin();
    ans += d(S, P[0]);
    for (int i = 1; i < N; i++) ans += d(P[i-1], P[i]);
    ans += d(P[N-1], S);
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
