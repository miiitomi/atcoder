// https://atcoder.jp/contests/abc100/tasks/abc100_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int D, N;
    cin >> D >> N;

    int cnt = 0;
    for (int x = 1; x <= 1e+9; x++) {
        int tmp = 0;
        int y = x;
        while (y % 100 == 0) {
            y /= 100;
            tmp++;
        }
        if (tmp == D) {
            cnt++;
            if (cnt == N) {
                cout << x << endl;
                return 0;
            }
        }
    }
}
