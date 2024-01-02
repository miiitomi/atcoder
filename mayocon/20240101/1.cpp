// https://atcoder.jp/contests/abc239/tasks/abc239_b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll X;
    cin >> X;
    if (X % 10 == 0 || X >= 0) cout << X / 10 << endl;
    else cout << X / 10 - 1 << endl;
}
