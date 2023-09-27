// https://atcoder.jp/contests/abc210/tasks/abc210_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll H, W, C;
const ll INF = 1e+18;

ll solve(vector<vector<ll>> &A) {
    vector<vector<ll>> T(H, vector<ll>(W, INF));
    ll ans = INF;
    for (int i = H-1; i >= 0; i--) {
        for (int j = W-1; j >= 0; j--) {
            if (j < W-1) T[i][j] = min(T[i][j], T[i][j+1]);
            if (i < H-1) T[i][j] = min(T[i][j], T[i+1][j]);
            ans = min(ans, T[i][j] + A[i][j] - C * (i + j));
            T[i][j] = min(T[i][j], A[i][j] + C * (i + j));
        }
    }
    return ans;
}

int main() {
    cin >> H >> W >> C;
    vector<vector<ll>> A(H, vector<ll>(W));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> A[i][j];

    ll ans = INF;
    ans = min(ans, solve(A));
    for (int i = 0; i < H; i++) reverse(A[i].begin(), A[i].end());
    ans = min(ans, solve(A));

    cout << ans << endl;
}
