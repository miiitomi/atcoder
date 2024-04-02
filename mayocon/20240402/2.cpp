// https://atcoder.jp/contests/abc289/tasks/abc289_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> C(M);
    vector<set<int>> a(M);
    for (int i = 0; i < M; i++) {
        cin >> C[i];
        for (int j = 0; j < C[i]; j++) {
            int x;
            cin >> x;
            a[i].insert(x);
        }
    }

    int ans = 0;
    for (int s = 1; s < (1 << M); s++) {
        bool is_ok = true;
        for (int x = 1; x <= N; x++) {
            bool tmp = false;
            for (int i = 0; i < M; i++) {
                if (!(s & (1 << i))) continue;
                if (a[i].count(x)) tmp = true;
            }
            if (!tmp) is_ok = false;
        }
        if (is_ok) ans++;
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
