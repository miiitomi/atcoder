// https://atcoder.jp/contests/abc065/tasks/abc065_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<bool> b(N, false);
    int x = 0, cnt = 0;
    while (true) {
        if (x == 1) {
            cout << cnt << "\n";
            return;
        }
        if (b[x]) {
            cout << -1 << "\n";
            return;
        }
        b[x] = true;
        x = a[x];
        cnt++;
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
