#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll left = -1, right = 1e+18;
    while (right - left > 1) {
        ll m = (right + left) / 2;
        ll x = m;
        bool is_ok = (x >= 0);
        for (int i = 0; i < N; i++) {
            x += A[i];
            if (x < 0) {
                is_ok = false;
                break;
            }
        }
        if (is_ok) right = m;
        else left = m;
    }
    for (int i = 0; i < N; i++) right += A[i];
    cout << right << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
