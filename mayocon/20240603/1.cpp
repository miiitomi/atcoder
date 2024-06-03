// https://atcoder.jp/contests/abc159/tasks/abc159_b
#include <bits/stdc++.h>
using namespace std;

bool is_kaibun(string &S, int l, int r) {
    for (int i = 0; i < (r-l); i++) {
        if (S[l-1+i] != S[r-1-i]) return false;
    }
    return true;
}

void solve() {
    string S;
    cin >> S;
    int N = S.size();
    if (is_kaibun(S, 1, N) && is_kaibun(S, 1, (N-1)/2) && is_kaibun(S, (N+3)/2, N)) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
