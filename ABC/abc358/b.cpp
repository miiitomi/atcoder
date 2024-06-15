#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, A;
    cin >> N >> A;
    ll t = 0;
    for (int i = 0; i < N; i++) {
        ll T;
        cin >> T;
        if (t <= T) {
            t = T + A;
        } else {
            t += A;
        }
        cout << t << endl;
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
