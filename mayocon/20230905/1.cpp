// https://atcoder.jp/contests/abc253/tasks/abc253_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> x(3);
    x[0] = a;
    x[1] = b;
    x[2] = c;
    sort(x.begin(), x.end());

    if (x[1] == b) cout << "Yes" << endl;
    else cout << "No" << endl;
}
