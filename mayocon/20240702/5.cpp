// https://atcoder.jp/contests/abc270/tasks/abc270_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll left = 0, right = 1e+18;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        ll tmp = 0;
        for (int i = 0; i < N; i++) {
            tmp += min(m, A[i]);
        }
        if (tmp > K) right = m;
        else left = m;
    }

    for (int i = 0; i < N; i++) {
        K -= min(left, A[i]);
        A[i] -= min(left, A[i]);
    }

    ll i = 0;
    while (K > 0) {
        if (A[i] > 0) {
            K--;
            A[i]--;
        }
        i++;
    }
    for (ll a : A) cout << a << " ";
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
