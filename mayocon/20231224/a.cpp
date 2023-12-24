// https://atcoder.jp/contests/abc269/tasks/abc269_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> S(10);
    for (int i = 0; i < 10; i++) cin >> S[i];
    int a=1e+9, b=-1, c=1e+9, d=-1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (S[i][j] == '#') {
                a = min(a, i);
                b = max(b, i);
                c = min(c, j);
                d = max(d, j);
            }
        }
    }
    cout << a + 1 << " " << b + 1 << "\n";
    cout << c + 1 << " " << d + 1 << "\n";
}
