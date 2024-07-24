// https://atcoder.jp/contests/abc314/tasks/abc314_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, H;
    cin >> N >> M >> H;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        B[i]--;
    }

    vector<ll> C(M, 0);
    set<pair<ll,ll>> L, U;
    for (int i = 0; i < M; i++) L.insert({0, i});
    vector<ll> Y(N+1, 0);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        ll t = B[i];
        if (L.count({C[t], t})) {
            L.erase({C[t], t});
            sum -= C[t];
            U.insert({C[t]+A[i], t});
        } else {
            U.erase({C[t], t});
            U.insert({C[t]+A[i], t});
        }
        C[t] += A[i];

        while (!U.empty() && !L.empty() && (*L.rbegin()).first > (*U.begin()).first) {
            pair<ll,ll> p = *L.rbegin();
            pair<ll,ll> q = *U.begin();
            sum += -p.first + q.first;
            L.erase(p);
            U.insert(p);
            U.erase(q);
            L.insert(q);
        }

        while (!U.empty() && sum + (*U.begin()).first <= H-1) {
            pair<ll,ll> p = *U.begin();
            sum += p.first;
            U.erase(p);
            L.insert(p);
        }
        Y[i+1] = U.size();
    }
    vector<ll> X(M+1, N);
    for (int i = 0; i <= N; i++) X[Y[i]] = i;

    for (ll x : X) cout << x << " ";
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
