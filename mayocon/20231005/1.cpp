// https://atcoder.jp/contests/abc278/tasks/abc278_b
#include <bits/stdc++.h>
using namespace std;

bool is_mimachigae(int a, int b, int c, int d) {
    swap(b, c);
    int s = 10*a + b, t = 10*c+d;
    if (!(0 <= s && s <= 23)) return false;
    if (!(0 <= t && t <= 59)) return false;
    return true;
}

int main() {
    int H, M;
    cin >> H >> M;

    while (true) {
        int a = H / 10, b = H % 10, c = M / 10, d = M % 10;
        if (is_mimachigae(a, b, c, d)) {
            cout << H << " " << M << endl;
            return 0;
        }
        M = (M + 1) % 60;
        if (M == 0) {
            H = (H + 1) % 24;
        }
    }
}
