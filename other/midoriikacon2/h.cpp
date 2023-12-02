#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll x1, y1, x2, y2;
    char d1, d2;
    cin >> x1 >> y1 >> d1;
    cin >> x2 >> y2 >> d2;

    if (x1 == x2) {
        if (y1 < y2) {
            if (d1 == 'U' && d2 == 'D') cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            if (d1 == 'D' && d2 == 'U') cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        return;
    } else if (y1 == y2) {
        if (x1 < x2) {
            if (d1 == 'R' && d2 == 'L') cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            if (d1 == 'L' && d2 == 'R') cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        return;
    }

    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
        swap(d1, d2);
    }

    if (y1 < y2) {
        if (d1 == 'U' && d2 == 'L') {
            ll px = x1, py = y2;
            if (abs(py - y1) == abs(x2 - px)) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else if (d1 == 'R' && d2 == 'D') {
            ll px = x2, py = y1;
            if (abs(px - x1) == abs(y2 - py)) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        if (d1 == 'R' && d2 == 'U') {
            ll px = x2, py = y1;
            if (abs(px - x1) == abs(py - y2)) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else if (d1 == 'D' && d2 == 'L') {
            ll px = x1, py = y2;
            if (abs(py - y1) == abs(px - x2)) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
