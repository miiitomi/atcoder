#include <bits/stdc++.h>
using namespace std;

int count(vector<string> &S, int i, int j) {
    int c = 0;
    for (int k = i; k <= i+1; k++) {
        for (int l = j; l <= j+1; l++) {
            if (S.at(k).at(l) == '#') {
                c++;
            }
        }
    }
    if (c % 2 == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S.at(i);
    }

    int ans = 0;

    for (int i = 0; i < H-1; i++) {
        for (int j = 0; j < W-1; j++) {
            ans += count(S, i, j);
        }
    }
    cout << ans << endl;
}