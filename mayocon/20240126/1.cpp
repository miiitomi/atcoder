// https://atcoder.jp/contests/abc122/tasks/abc122_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    int N = S.size();
    set<char> C{'A', 'C', 'G', 'T'};
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            bool ok = true;
            for (int k = i; k <= j; k++) {
                char c = S[k];
                if (!C.count(c)) ok = false;
            }
            if (ok) ans = max(ans, j-i+1);
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
