// https://atcoder.jp/contests/abc299/tasks/abc299_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int ans = -1;
    int tmp = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') tmp++;
        else {
            ans = max(ans, tmp);
            tmp = 0;
        }
    }
    ans = max(ans, tmp);

    if (ans == N || ans == 0) cout << -1 << endl;
    else cout << ans << endl;
}
