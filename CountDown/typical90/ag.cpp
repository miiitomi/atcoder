#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    if (H == 1 || W == 1) {
        cout << max(H, W) << endl;
        return 0;
    }

    H = (H + 1) / 2;
    W = (W + 1) / 2;
    cout << H * W << endl;
}
