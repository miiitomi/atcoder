// https://atcoder.jp/contests/abc266/tasks/abc266_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> X(4, vector<int>(2));
    for (int i = 0; i < 4; i++) for (int j = 0; j < 2; j++) cin >> X[i][j];

    for (int i = 0; i < 4; i++) {
        int j = (i + 2) % 4;
        bool s = ((X[j][0] - X[i][0]) * X[(i+1) % 4][1] > (X[j][1] - X[i][1])* X[(i+1) % 4][0] + (X[j][0] - X[i][0])*X[i][1] - ((X[j][1] - X[i][1])*X[i][0]));
        bool t = ((X[j][0] - X[i][0]) * X[(i+3) % 4][1] > (X[j][1] - X[i][1])* X[(i+3) % 4][0] + (X[j][0] - X[i][0])*X[i][1] - ((X[j][1] - X[i][1])*X[i][0]));

        if (s == t) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
