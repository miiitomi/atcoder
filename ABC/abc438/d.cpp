#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T> struct CumulativeSum {
    int N;
    vector<T> data;

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

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    for (ll &a: A) cin >> a;
    for (ll &a: B) cin >> a;
    for (ll &a: C) cin >> a;
    CumulativeSum<ll> SA(A), SB(B), SC(C);
    ll ans = SA.query(0, N-2) + SB.query(N-2, N-1) + SC.query(N-1, N);
    ll y = N-1;
    for (ll x = N-3; x >= 1; x--) {
        if (SB.query(x+1, y) < SC.query(x+1, y)) {
            y = x+1;
        }
        ans = max(ans, SA.query(0, x) + SB.query(x, y) + SC.query(y, N));
    }
    cout << ans << "\n";
}
