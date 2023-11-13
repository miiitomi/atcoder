// https://atcoder.jp/contests/abc283/tasks/abc283_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int x = 1;
    for (int i = 0; i < b; i++) x *= a;

    cout << x << endl;
}
