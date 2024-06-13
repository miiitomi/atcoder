// https://atcoder.jp/contests/abc091/tasks/abc091_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N;
    multiset<string> A, B;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        A.insert(s);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        string t;
        cin >> t;
        B.insert(t);
    }

    int ans = 0;
    for (string s : A) {
        ans = max(ans, (int)A.count(s) - (int)B.count(s));
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
