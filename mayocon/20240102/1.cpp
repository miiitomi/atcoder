// https://atcoder.jp/contests/abc135/tasks/abc135_a
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;
    ll x = (a + b)/ 2;

    if (abs(a-x) == abs(b-x)) cout << x << endl;
    else cout << "IMPOSSIBLE" << endl;
}
