// https://atcoder.jp/contests/abc098/tasks/abc098_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;

    int ans = -1;
    for (int i = 1; i < N; i++) {
        set<char> S, T;
        for (int j = 0; j < i; j++) S.insert(s[j]);
        for (int j = i; j < N; j++) T.insert(s[j]);

        int tmp = 0;
        for (char c : S) if (T.count(c)) tmp++;

        ans = max(ans, tmp);
    }

    cout << ans << endl;
}
