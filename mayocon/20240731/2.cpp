// https://atcoder.jp/contests/abc302/tasks/abc302_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    string snuke = "snuke";
    string ekuns = "ekuns";
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (j+5 <= W) {
                string tmp;
                for (int k = 0; k < 5; k++) tmp.push_back(S[i][j+k]);
                if (tmp == snuke) {
                    for (int k = 0; k < 5; k++) {
                        cout << i+1 << " " << j+1+k << endl;
                    }
                    return;
                }
                if (tmp == ekuns) {
                    for (int k = 4; k >= 0; k--) {
                        cout << i+1 << " " << j+1+k << endl;
                    }
                    return;
                }
            }
            if (i+5 <= H) {
                string tmp;
                for (int k = 0; k < 5; k++) tmp.push_back(S[i+k][j]);
                if (tmp == snuke) {
                    for (int k = 0; k < 5; k++) {
                        cout << i+1+k << " " << j+1 << "\n";
                    }
                    return;
                }
                if (tmp == ekuns) {
                    for (int k = 4; k >= 0; k--) {
                        cout << i+1+k << " " << j+1 << "\n";
                    }
                    return;
                }
            }
            if (i+5 <= H && j+5 <= W) {
                string tmp;
                for (int k = 0; k < 5; k++) {
                    tmp.push_back(S[i+k][j+k]);
                }
                if (tmp == snuke) {
                    for (int k = 0; k < 5; k++) {
                        cout << i+1+k << " " << j+1+k << "\n";
                    }
                    return;
                }
                if (tmp == ekuns) {
                    for (int k = 4; k >= 0; k--) {
                        cout << i+1+k << " " << j+1+k << "\n";
                    }
                    return;
                }
            }
            if (i-4 >= 0 && j+5 <= W) {
                string tmp;
                for (int k = 0; k < 5; k++) {
                    tmp.push_back(S[i-k][j+k]);
                }
                if (tmp == snuke) {
                    for (int k = 0; k < 5; k++) {
                        cout << i+1-k << " " << j+1+k << "\n";
                    }
                    return;
                }
                if (tmp == ekuns) {
                    for (int k = 4; k >= 0; k--) {
                        cout << i+1-k << " " << j+1+k << "\n";
                    }
                    return;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
