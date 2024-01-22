// https://atcoder.jp/contests/arc144/tasks/arc144_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, a, b;
    cin >> N >> a >> b;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll left = *min_element(A.begin(), A.end()), right = 1 + *max_element(A.begin(), A.end());
    while (right - left > 1) {
        ll mid = (right + left) / 2;
        ll s=0, t=0;
        for (ll x : A) {
            if (x > mid) {
                t += (x - mid) / b;
            } else if (x < mid) {
                s += (mid - x + a - 1) / a;
            }
        }
        if (t >= s) left = mid;
        else right = mid;
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
