// https://atcoder.jp/contests/abc216/tasks/abc216_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x=0, y=0;
    char c;
    cin >> c;
    x += (int)(c-'0');
    cin >> c;
    if (c != '.') {
        x *= 10;
        x += (int)(c-'0');
        cin >> c;
    }
    cin >> c;
    y += (int)(c-'0');

    if (y <= 2) cout << x << "-" << endl;
    else if (y <= 6) cout << x << endl;
    else cout << x << "+" << endl;
}
