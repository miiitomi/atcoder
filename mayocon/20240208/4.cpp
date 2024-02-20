// https://atcoder.jp/contests/abc269/tasks/abc269_e
#include <bits/stdc++.h>
using namespace std;

int query(int a, int b, int c, int d) {
    cout << "? " << a+1 << " " << b << " " << c+1 << " " << d << endl;
    int x;
    cin >> x;
    return x;
}

void solve() {
    int N;
    cin >> N;

    int x, y;
    int l = 0, r = N;
    while (r - l > 1) {
        int m = (r + l) / 2;
        int res = query(l, m, 0, N);
        if (res < m-l) r = m;
        else l = m;
    }
    x = l;

    l = 0;
    r = N;
    while (r - l > 1) {
        int m = (r + l) / 2;
        int res = query(0, N, l, m);
        if (res < m-l) r = m;
        else l = m;
    }
    y = l;

    cout << "! " << x+1 << " " << y+1 << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
