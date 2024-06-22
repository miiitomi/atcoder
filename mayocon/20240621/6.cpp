// https://atcoder.jp/contests/abc227/tasks/abc227_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll left = 1, right = 1e+18;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        ll sum = 0;
        for (int i = 0; i < N; i++) sum += min(A[i], m);
        if (sum / K >= m) {
            left = m;
        } else {
            right = m;
        }
    }

    cout << left << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
