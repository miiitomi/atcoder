// https://atcoder.jp/contests/abc098/tasks/abc098_b
#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int ans = -1;
    for (int i = 0; i < N-1; i++) {
        set<char> T1, T2;
        for (int j = 0; j < N; j++) {
            char c = S[j];
            if (j <= i) T1.insert(c);
            else T2.insert(c);
        }

        int tmp = 0;
        for (char a = 'a'; a <= 'z'; a++) {
            if (T1.count(a) && T2.count(a)) tmp++;
        }

        ans = max(ans, tmp);
    }
    cout << ans << endl;
}
