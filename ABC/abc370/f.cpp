#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> struct CumulativeSum {
    int N;
    vector<T> data;

    CumulativeSum() {
        N = 0;
        data = vector<T>{};
    }

    CumulativeSum(vector<T> &A) {
        N = A.size();
        data.assign(N+1, 0);
        for (int i = 0; i < N; i++) data[i+1] = data[i] + A[i];
    }

    T query(int l, int r) {
        // Return Sum of [l, r)
        return data[r]-data[l];
    }
};

ll N, K;
vector<ll> A;
CumulativeSum<ll> S;

ll f(ll x) {
    vector<pair<ll,ll>> X(N, {0,0}), Y(N, {0,0});
    for (int i = N-1; i >= 0; i--) {
        if (i == N-1) {
            if (A[i] >= x) X[i] = {1, 0};
            else X[i] = {0, A[i]};
        } else {
            if (S.query(i, N) < x) {
                X[i] = {0, S.query(i, N)};
            } else {
                ll left = i, right = N;
                while (right - left > 1) {
                    ll m = (left+right)/2;
                    if (S.query(i, m) >= x) right = m;
                    else left = m;
                }
                if (right == N) X[i] = {1, 0};
                else X[i] = {1 + X[right].first, X[right].second};
            }
        }
    }
    for (int i = 1; i < N; i++) {
        if (i == 1) {
            if (A[i-1] >= x) Y[i] = {1, 0};
            else Y[i] = {0, A[i-1]};
        } else {
            if (S.query(0, i) < x) {
                Y[i] = {0, S.query(0, i)};
            } else {
                ll left = 0, right = i;
                while (right-left > 1) {
                    ll m = (left+right)/2;
                    if (S.query(m, i) >= x) left = m;
                    else right = m;
                }
                if (left == 0) Y[i] = {1, 0};
                else Y[i] = {Y[left].first + 1, Y[left].second};
            }
        }
    }
    bool ok = false;
    ll ans = N;
    for (int i = 0; i < N; i++) {
        ll cnt = Y[i].first + X[i].first + ((X[i].second + Y[i].second) >= x);
        if (cnt >= K) {
            ok = true;
            ans--;
        }
    }
    if (ok) return ans;
    else return -1;
}

void solve() {
    cin >> N >> K;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    S = CumulativeSum<ll>(A);
    ll M = S.query(0, N);
    ll left = 1, right = M+1;
    while (right - left > 1) {
        ll x = (left + right)/2;
        if (f(x) >= 0) left = x;
        else right = x;
    }
    cout << left << " " << f(left) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
