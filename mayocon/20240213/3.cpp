// https://atcoder.jp/contests/abc318/tasks/abc318_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, D, P;
    cin >> N >> D >> P;
    ll ans = 0;
    vector<ll> F(N);
    for (int i = 0; i < N; i++) {
        cin >> F[i];
        ans+= F[i];
    }
    sort(F.begin(), F.end());

    while (!F.empty()) {
        ll tmp = 0;
        for (int i = 0; i < D && !F.empty(); i++) {
            tmp += F.back();
            F.pop_back();
        }
        if (tmp >= P) {
            ans = ans - tmp + P;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
