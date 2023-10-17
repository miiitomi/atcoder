// https://atcoder.jp/contests/abc266/tasks/abc266_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> p(4, vector<int>(2));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> p[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        int ax = p[(i+1)%4][0] - p[i][0];
        int ay = p[(i+1)%4][1] - p[i][1];
        int bx = p[(i-1+4)%4][0] - p[i][0];
        int by = p[(i-1+4)%4][1] - p[i][1];

        if (ax*by-ay*bx < 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
