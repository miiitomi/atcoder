#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    int x = (W + 1)/2;
    int y = (H + 1)/2;
    if (H != 1 && W != 1) cout << x * y << endl;
    else cout << max(H, W) << endl;
}
