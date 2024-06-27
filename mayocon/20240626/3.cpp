// https://atcoder.jp/contests/abc162/tasks/abc162_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
struct Fenwick {
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

    T sum(int i) {
        // compute sum of a[i] with i in [0, i)
        T ans = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            ans += data[idx];
        }
        return ans;
    }

    T sum(int a, int b) {
        // compute sum of a[i] with i in [a, b)
        return sum(b) - sum(a);
    }
};

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    Fenwick<ll> R(N), G(N), B(N);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') R.add(i, 1);
        else if (S[i] == 'G') G.add(i, 1);
        else B.add(i, 1);
    }

    ll ans = 0;
    for (int i = 1; i < N-1; i++) {
        if (S[i] == 'R') ans += G.sum(0, i)*B.sum(i+1, N) + B.sum(0, i)*G.sum(i+1, N);
        else if (S[i] == 'G') ans += B.sum(0,i)*R.sum(i+1, N) + R.sum(0,i)*B.sum(i+1,N);
        else ans += R.sum(0,i)*G.sum(i+1,N) + G.sum(0,i)*R.sum(i+1,N);
        for (int k = 1; i-k >= 0 && k+i <= N-1; k++) {
            if (S[i]!=S[i-k] && S[i]!=S[i+k] && S[i-k]!=S[i+k]) ans--;
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
