#include <bits/stdc++.h>
using namespace std;

int v1, v2, v3;
int a1=7, b1=7, c1=7;

bool is_true(int a2, int b2, int c2, int a3, int b3, int c3) {
    int w1=3*(7*7*7), w2=0, w3=0;

    int x = max(7, max(a2, a3)), X = min(14, min(a2, a3)+7);
    int y = max(7, max(b2, b3)), Y = min(14, min(b2, b3)+7);
    int z = max(7, max(c2, c3)), Z = min(14, min(c2, c3)+7);
    w3 = max(0, X - x) * max(0, Y-y) * max(0, Z-z);

    if (v3 != w3) return false;

    w1 -= 3*w3;

    x = 0;
    y = 0;
    z = 0;
    if (abs(a1 - a3) < 7) x = min(a1+7, a3+7) - max(a1, a3);
    if (abs(b1 - b3) < 7) y = min(b1+7, b3+7) - max(b1, b3);
    if (abs(c1 - c3) < 7) z = min(c1+7, c3+7) - max(c1, c3);
    w2 += x*y*z;

    x = 0;
    y = 0;
    z = 0;
    if (abs(a2 - a3) < 7) x = min(a2+7, a3+7) - max(a2, a3);
    if (abs(b2 - b3) < 7) y = min(b2+7, b3+7) - max(b2, b3);
    if (abs(c2 - c3) < 7) z = min(c2+7, c3+7) - max(c2, c3);
    w2 += x*y*z;

    x = 0;
    y = 0;
    z = 0;
    if (abs(a2 - a1) < 7) x = min(a2+7, a1+7) - max(a2, a1);
    if (abs(b2 - b1) < 7) y = min(b2+7, b1+7) - max(b2, b1);
    if (abs(c2 - c1) < 7) z = min(c2+7, c1+7) - max(c2, c1);
    w2 += x*y*z;

    w2 -= 3*w3;

    if (v2 != w2) return false;

    w1 -= 2*w2;
    return v1 == w1;
}

void solve() {
    cin >> v1 >> v2 >> v3;

    for (int a2 = 0; a2 <= 20; a2++) {
        for (int b2 = 0; b2 <= 20; b2++) {
            for (int c2 = 0; c2 <= 20; c2++) {
                for (int a3 = 0; a3 <= 20; a3++) {
                    for (int b3 = 0; b3 <= 20; b3++) {
                        for (int c3 = 0; c3 <= 20; c3++) {
                            if (is_true(a2, b2, c2, a3, b3, c3)) {
                                cout << "Yes\n";
                                cout << "7 7 7 ";
                                cout << a2 << " " << b2 << " " << c2 << " ";
                                cout << a3 << " " << b3 << " " << c3 << "\n";
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
