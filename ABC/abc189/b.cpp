#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    int minimum = 100;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A.at(i).at(j);
            if (minimum > A.at(i).at(j)) {
                minimum = A.at(i).at(j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans += A.at(i).at(j) - minimum;
        }
    }
    cout << ans << endl;
    return 0;
}