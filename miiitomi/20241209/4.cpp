// https://atcoder.jp/contests/arc160/tasks/arc160_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> struct Fenwick {
    int n;
    vector<T> data;

    Fenwick(int _n) {
        n = _n + 1;
        data.assign(n, 0);
    }

    void add(int i, T x) {
        // Add x to a[i] (0-indexed).
        for (int idx = i + 1; idx < n; idx += (idx & -idx)) {
            data[idx] += x;
        }
    }

    T _sum(int i) {
        // compute sum of a[k] for k in [0, i)
        T ans = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            ans += data[idx];
        }
        return ans;
    }

    T query(int a, int b) {
        // compute sum of a[k] for k in [a, b)
        return _sum(b) - _sum(a);
    }
};

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    Fenwick<ll> f(N);
    vector<bool> remain(N, true);
    for (ll l = 0; l < N; l++) {
        ll a = A[l];
        ll left = a - f.query(0, a);
        ll m = N + (N-l-1)*(N-l-2)/2;
        ll right = (N-1-a) - f.query(a, N);
        if (K <= left) {
            ll r = -1;
            for (int i = 0; i < N; i++) {
                if (remain[i]) K--;
                if (K == 0) {
                    for (int j = 0; j < N; j++) {
                        if (A[j] == i) {
                            r = j;
                            break;
                        }
                    }
                    break;
                }
            }
            for (int i = 0; i < (r-l+1)/2; i++) {
                swap(A[l+i], A[r-i]);
            }
            break;
        } else if (left + m < K) {
            ll R = left + m + right + 1;
            ll r = -1;
            for (int i = N-1; i >= 0; i--) {
                if (remain[i]) R--;
                if (R == K) {
                    for (int j = 0; j < N; j++) {
                        if (A[j] == i) {
                            r = j;
                            break;
                        }
                    }
                    break;
                }
            }
            for (int i = 0; i < (r - l + 1)/2; i++) {
                swap(A[l+i], A[r-i]);
            }
            break;
        }
        K -= left;
        f.add(a, 1);
        remain[a] = false;
    }

    for (int i = 0; i < N; i++) {
        cout << A[i]+1;
        if (i == N-1) cout << endl;
        else cout << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
