#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_crossing(pair<ll,ll> &a0, pair<ll,ll> &a1, pair<ll,ll> &b0, pair<ll,ll> &b1) {
    if (a0 == b0 || a0 == b1 || a1 == b0 || a1 == b1) return true;
    auto [x0, y0] = a0;
    auto [x1, y1] = a1;
    auto [x2, y2] = b0;
    auto [x3, y3] = b1;
    long long v0 = (x0 - x1) * (y2 - y0) + (y0 - y1) * (x0 - x2);
    long long v1 = (x0 - x1) * (y3 - y0) + (y0 - y1) * (x0 - x3);
    long long v2 = (x2 - x3) * (y0 - y2) + (y2 - y3) * (x2 - x0);
    long long v3 = (x2 - x3) * (y1 - y2) + (y2 - y3) * (x2 - x1);

    if (v0 == 0 && v1 == 0) {
        return (min(x0, x1) <= x2 && x2 <= max(x0, x1) && min(y0, y1) <= y2 && y2 <= max(y0, y1))
            || (min(x0, x1) <= x3 && x3 <= max(x0, x1) && min(y0, y1) <= y3 && y3 <= max(y0, y1))
            || (min(x2, x3) <= x0 && x0 <= max(x2, x3) && min(y2, y3) <= y0 && y0 <= max(y2, y3))
            || (min(x2, x3) <= x1 && x1 <= max(x2, x3) && min(y2, y3) <= y1 && y1 <= max(y2, y3));
    }

    if (make_pair(y0, x0) == make_pair(y2, x2) || make_pair(y0, x0) == make_pair(y3, x3) || make_pair(y1, x1) == make_pair(y2, x2) || make_pair(y1, x1) == make_pair(y3, x3)) {
        return false;
    }

    return v0 * v1 <= 0 && v2 * v3 <= 0;
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        pair<ll,ll> a0, a1, b0, b1;
        cin >> a0.first >> a0.second;
        cin >> a1.first >> a1.second;
        cin >> b0.first >> b0.second;
        cin >> b1.first >> b1.second;
        if (is_crossing(a0, a1, b0, b1)) cout << "1\n";
        else cout << "0\n";
    }
}
