// https://atcoder.jp/contests/abc116/tasks/abc116_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> h(N), a(N, 0);
    for (int i = 0; i < N; i++) cin >> h[i];
    int ans = 0;

    while (true) {
        int l=-1, r=-1;
        for (int i = 0; i < N; i++) {
            if (h[i] > a[i]) {
                l = i;
                break;
            }
        }
        if (l == -1) break;
        for (int i = l; i < N; i++) {
            if (a[i] < h[i]) r = i;
            else break;
        }

        ans++;
        for (int i = l; i <= r; i++) a[i]++;
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
