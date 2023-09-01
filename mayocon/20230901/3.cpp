// https://atcoder.jp/contests/abc085/tasks/abc085_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;

    for (int x = 0; x <= N; x++) {
        for (int y = 0; x + y <= N; y++) {
            int z = N - x - y;
            int K = 10000 * x + 5000 * y + 1000*z;
            if (K == Y) {
                cout << x << " " << y << " " << z << endl;
                return 0;
            }
        }
    }

    cout << "-1 -1 -1" << endl;
}
