// https://atcoder.jp/contests/abc266/tasks/abc266_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> x(4), y(4);
    for (int i = 0; i < 4; i++) cin >> x[i] >> y[i];

    for (int i = 0; i < 4; i++) {
        int ax = x[(i+1)%4] - x[i];
        int ay = y[(i+1)%4] - y[i];
        int bx = x[(i+3)%4] - x[i];
        int by = y[(i+3)%4] - y[i];
        int q = ax*by - ay*bx;
        if (q < 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
