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
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    CumulativeSum<ll> C(A);
    ll ans = 0;
    for (ll l = 1; l <= N; l++) {
        for (ll r = l; r <= N; r++) {
            ll sum = C.query(l-1, r);
            bool ok = true;
            for (ll x = l; x <= r; x++) {
                ll a = A[x-1];
                if (sum % a == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans++;
        }
    }
    cout << ans << "\n";
}
