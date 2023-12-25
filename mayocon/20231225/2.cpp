// https://atcoder.jp/contests/abc329/tasks/abc329_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    string S;
    cin >> N >> S;
    ll ans = 0;

    for (char c = 'a'; c <= 'z'; c++) {
        ll mv=0, tmp = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] == c) tmp++;
            else {
                mv = max(mv, tmp);
                tmp = 0;
            }
        }
        mv = max(mv, tmp);
        ans += mv;
    }

    cout << ans << endl;
}
