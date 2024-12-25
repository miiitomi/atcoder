// https://atcoder.jp/contests/abc274/tasks/abc274_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

struct fraction {
    ll numerator = 0, denominator=1;

    fraction(ll _numerator, ll _denominator) {
        numerator = _numerator;
        denominator = _denominator;
    }
    
    bool operator<(const fraction &other) {
        return numerator*other.denominator < other.numerator*denominator;
    }
    bool operator==(const fraction &other) {
        return numerator*other.denominator == other.numerator*denominator;
    }
};

void solve() {
    ll N, A;
    cin >> N >> A;
    vector<ll> W(N), X(N), V(N);
    for (int i = 0; i < N; i++) cin >> W[i] >> X[i] >> V[i];
    ll ans = -INF;
    for (int i = 0; i < N; i++) {
        vector<fraction> L(N, fraction(-1,1)), R(N, fraction(-1,1)), T;
        for (int j = 0; j < N; j++) {
            if (V[j] == V[i]) {
                if (X[i] <= X[j] && X[j] <= X[i]+A) {
                    L[j] = {0, 1};
                    R[j] = {(ll)1e+14, 1};
                    T.push_back(L[j]);
                    T.push_back(R[j]);
                }
                continue;
            }
            if (V[j] < V[i]) {
                if (X[j] < X[i]) continue;
                R[j] = {X[j] - X[i], V[i] - V[j]};
                L[j] = {X[j] - X[i] - A, V[i] - V[j]};
                if (L[j] < fraction(0,1)) L[j] = {0, 1};
                T.push_back(L[j]);
                T.push_back(R[j]);
            } else {
                if (X[j] > X[i]+A) continue;
                L[j] = {X[i]-X[j], V[j]-V[i]};
                R[j] = {X[i]-X[j]+A, V[j]-V[i]};
                if (L[j] < fraction(0, 1)) L[j] = {0, 1};
                T.push_back(L[j]);
                T.push_back(R[j]);
            }
        }
        sort(T.begin(), T.end());
        T.erase(unique(T.begin(), T.end()), T.end());
        sort(T.begin(),T.end());
        vector<ll> cnt(T.size(), 0);
        for (int j = 0; j < N; j++) {
            if (L[j] < fraction(0, 1)) continue;
            auto iter = lower_bound(T.begin(), T.end(), L[j]);
            cnt[distance(T.begin(), iter)] += W[j];
            iter = lower_bound(T.begin(), T.end(), R[j]);
            iter++;
            if (iter < T.end()) cnt[distance(T.begin(), iter)] -= W[j];
        }
        for (int t = 0; t < (int)T.size(); t++) {
            ans = max(ans, cnt[t]);
            if (t+1 < (int)T.size()) {
                cnt[t+1] += cnt[t];
            }
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
