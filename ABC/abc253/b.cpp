#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    int a = -1;
    int b = -1;
    int c = -1;
    int d = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char x;
            cin >> x;
            if (x == 'o') {
                if (a == -1) {
                    a = i;
                    b = j;
                } else {
                    c = i;
                    d = j;
                }
            }
        }
    }

    cout << max(a, c) - min(a, c) + max(b, d) - min(b, d) << endl;
}
