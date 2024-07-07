// https://atcoder.jp/contests/abc300/tasks/abc300_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int H, W;

vector<string> tate_shift(int k, vector<string> &S) {
    vector<string> T(H, string(W, '.'));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            T[(i+k)%H][j] = S[i][j];
        }
    }
    return T;
}

vector<string> yoko_shift(int k, vector<string> &S) {
    vector<string> T(H, string(W, '.'));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            T[i][(j+k)%W] = S[i][j];
        }
    }
    return T;
}

void solve() {
    cin >> H >> W;
    vector<string> A(H), B(H);
    for (int i = 0; i < H; i++) cin >> A[i];
    for (int i = 0; i < H; i++) cin >> B[i];

    for (int k = 0; k < H; k++) {
        vector<string> S = tate_shift(k, A);
        for (int l = 0; l < W; l++) {
            vector<string> T = yoko_shift(l, S);
            if (T == B) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
