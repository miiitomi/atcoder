// https://atcoder.jp/contests/abc205/tasks/abc205_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    while (Q--) {
        ll K;
        cin >> K;
        ll left = 1, right = 2e+18;
        while (right - left > 1) {
            ll m = (right + left) / 2;
            auto iter = lower_bound(A.begin(), A.end(), m+1);
            ll c = m - distance(A.begin(), iter);

            bool is_in = false;
            if (iter != A.begin()) {
                iter--;
                if (*iter == m) is_in = true;
            }

            if (c > K || (c == K && is_in)) right = m;
            else left = m;
        }
        cout << left << "\n";
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
