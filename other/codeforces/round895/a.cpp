#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    int mid = (a + b + 1) / 2.0;

    cout << (mid - a) / c + (bool)((mid-a)%c) << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
