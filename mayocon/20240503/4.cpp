// https://atcoder.jp/contests/abc084/tasks/abc084_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> C(N-1), S(N-1), F(N-1);
    for (int i = 0; i < N-1; i++) cin >> C[i] >> S[i] >> F[i];

    for (int i = 0; i < N; i++) {
        ll time = 0;
        for (ll tmp = i; tmp < N-1; tmp++) {
            if (time <= S[tmp]) {
                time = S[tmp] + C[tmp];
            } else {
                ll p = time - S[tmp];
                ll c;
                if (p % F[tmp] == 0) c = p / F[tmp];
                else c = p / F[tmp] + 1;
                time = S[tmp] + c*F[tmp] + C[tmp];
            }
        }
        cout << time << "\n";
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
