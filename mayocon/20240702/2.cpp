// https://atcoder.jp/contests/abc098/tasks/abc098_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ans = -1;
    for (int k = 1; k <= N-1; k++) {
        set<char> x, y;
        for (int i = 0; i < k; i++) x.insert(S[i]);
        for (int i = k; i < N; i++) y.insert(S[i]);

        int tmp = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (x.count(c) && y.count(c)) tmp++;
        }
        ans = max(ans, tmp);
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
