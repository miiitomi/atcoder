// https://atcoder.jp/contests/abc207/tasks/abc207_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> L(N), R(N);
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t >> L[i] >> R[i];
        L[i] *= 2;
        R[i] *= 2;
        if (t == 1) {
            R[i]++;
        } else if (t == 3) {
            L[i]++;
            R[i]++;
        } else if (t == 4) {
            L[i]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (L[i] == L[j]) {
                ans++;
            } else if (L[i] < L[j]) {
                if (L[j] < R[i]) ans++;
            } else if (L[j] < L[i]) {
                if (L[i] < R[j]) ans++;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
