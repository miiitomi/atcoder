// https://atcoder.jp/contests/abc253/tasks/abc253_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(3);
    for (int i = 0; i < 3; i++) cin >> v[i];
    int b = v[1];
    sort(v.begin(), v.end());

    if (b == v[1]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
