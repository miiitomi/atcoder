// https://atcoder.jp/contests/abc188/tasks/abc188_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;
    if (X > Y) swap(X, Y);

    if (X+3 > Y) cout << "Yes" << endl;
    else cout << "No" << endl;
}
