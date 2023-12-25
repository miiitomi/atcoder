#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> dx{0, 0, 1, 1}, dy{0, 1, 0, 1};

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W, 0)), B(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> A[i][j];
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> B[i][j];

    ll ans = 0;
    for (int i = 0; i < H-1; i++) {
        for (int j = 0; j < W-1; j++) {
            ll x = B[i][j] - A[i][j];
            ans += abs(x);
            for (int k = 0; k < 4; k++) {
                int s = i + dx[k], t = j + dy[k];
                A[s][t] += x;
            }
        }
    }

    if (A == B) cout << "Yes\n" << ans << endl;
    else cout << "No" << endl;
}
