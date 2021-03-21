#include <bits/stdc++.h>
using namespace std;

int H, W, A, B;

int dfs(int i, int s, int a, int b) {
    if (i == H * W) {
        if (a == 0 && b == 0) return 1;
        else return 0;
    }

    if (s & (1 << i)) {
        return dfs(i+1, s, a, b);
    }

    int ans = dfs(i+1, (s | (1 << i)), a, b-1);

    if (((i + 1) % W) && ((s & (1 << (i + 1))) == 0)) {
        ans += dfs(i+1, (s | (1 << i) | (1 << (i + 1))), a-1, b);
    }

    if ((i + W < W * H) && ((s & (1 << (i + W))) == 0)) {
        ans += dfs(i+1, (s | (1 << i) | (1 << (i + W))), a-1, b);
    }

    return ans;
}

int main() {
    cin >> H >> W >> A >> B;
    cout << dfs(0, 0, A, B) << endl;
}