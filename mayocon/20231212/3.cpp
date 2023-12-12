// https://atcoder.jp/contests/abc107/tasks/abc107_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for (int i = 0; i < H; i++) cin >> a[i];

    bool done = false;
    while (!done) {
        done = true;
        for (int i = 0; i < H; i++) {
            bool can_delete = true;
            for (int j = 0; j < W; j++) {
                if (a[i][j] != '.') {
                    can_delete = false;
                    break;
                }
            }
            if (can_delete) {
                done = false;
                vector<string> b;
                for (int k = 0; k < H; k++) {
                    if (k != i) b.push_back(a[k]);
                }
                swap(a, b);
                H--;
                break;
            }
        }

        if (!done) continue;

        for (int j = 0; j < W; j++) {
            bool can_delete = true;
            for (int i = 0; i < H; i++) {
                if (a[i][j] != '.') {
                    can_delete = false;
                    break;
                }
            }
            if (can_delete) {
                done = false;
                vector<string> b(H, "");
                for (int i = 0; i < H; i++) {
                    for (int k = 0; k < W; k++) {
                        if (k != j) b[i].push_back(a[i][k]);
                    }
                }
                swap(a, b);
                W--;
                break;
            }
        }
    }

    for (string s : a) cout << s << endl;
}
