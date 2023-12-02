#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f(ll N, ll X, ll a) {
    if (a - (N-1) <= 0) return false;
    ll s = N*(2*a - N + 1)/2;
    return s >= X;
}

void solve() {
    ll N, X;
    cin >> N >> X;
    ll xx = X;

    vector<ll> A(N, 0);
    for (int i = 0; i < N; i++) {
        ll left = -1, right = xx;
        if (i != 0) right = A[i-1]-1;
        while (right - left > 1) {
            ll mid = (right + left) / 2;
            if (f(N-i, X, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        A[i] = right;
        X -= right;
    }

    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        if (A[i] <= 0) {
            cout << -1 << endl;
            return;
        } else if (i < N-1 && A[i] <= A[i+1]) {
            cout << -1 << endl;
            return;
        }
    }

    if (sum != xx) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (i < N-1) cout << A[i] << " ";
        else cout << A[i] << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
