// https://atcoder.jp/contests/abc199/tasks/abc199_a
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    if (a*a + b*b < c*c) cout << "Yes" << endl;
    else cout << "No" << endl;
}
