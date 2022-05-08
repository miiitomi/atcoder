#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, R, C;
    cin >> H >> W >> R >> C;
    int ans = 0;
    if (R-1 >= 1) ans++;
    if (R+1 <= H) ans++;
    if (C-1 >= 1) ans++;
    if (C+1 <= W) ans++;
    cout << ans << endl;
}
