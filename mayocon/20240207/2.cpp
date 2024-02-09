// https://atcoder.jp/contests/abc066/tasks/abc066_b
#include <bits/stdc++.h>
using namespace std;

bool is_gu(string T) {
    if (T.size() % 2 == 1) return false;
    int N = T.size();
    string a = "", b = "";
    for (int i = 0; i < N/2; i++) {
        a.push_back(T[i]);
        b.push_back(T[N-1-i]);
    }
    reverse(b.begin(), b.end());
    return a == b;
}

void solve() {
    string S;
    cin >> S;
    int N = S.size(), ans = 0;
    for (int i = 0; i < N-1; i++) {
        string T = "";
        for (int j = 0; j <= i; j++) T.push_back(S[j]);
        if (is_gu(T)) ans = max(ans, (int)T.size());
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
