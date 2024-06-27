// https://atcoder.jp/contests/abc237/tasks/abc237_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    int head = 0, tail = 0;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        if (S[i] == 'a') head++;
        else break;
    }
    for (int i = N-1; i >= 0; i--) {
        if (S[i] == 'a') tail++;
        else break;
    }
    while (tail < head) {
        S.push_back('a');
        tail++;
    }

    string T = S;
    reverse(T.begin(), T.end());
    if (S == T) cout << "Yes\n";
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
