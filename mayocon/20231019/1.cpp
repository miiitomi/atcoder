// https://atcoder.jp/contests/abc060/tasks/abc060_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    if (a[(int)a.size()-1] == b[0] && b[(int)b.size()-1] == c[0]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
