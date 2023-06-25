#include <bits/stdc++.h>
using namespace std;
const int N = 30;

int main() {
    vector<vector<int>> b(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> b[i][j];
        }
    }

    cout << 0 << endl;
}
