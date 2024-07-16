// https://atcoder.jp/contests/abc107/tasks/abc107_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    bool update = true;
    while (update) {
        update = false;
        for (int i = 0; i < H; i++) {
            bool can_erase = true;
            for (int j = 0; j < W; j++) {
                if (S[i][j] == '#') {
                    can_erase = false;
                    break;
                }
            }
            if (can_erase) {
                H--;
                S.erase(S.begin()+i);
                update = true;
                break;
            }
        }
    }
    update = true;
    while (update) {
        update = false;
        for (int j = 0; j < W; j++) {
            bool can_erase = true;
            for (int i = 0; i < H; i++) {
                if (S[i][j] == '#') {
                    can_erase = false;
                    break;
                }
            }
            if (can_erase) {
                for (int i = 0; i < H; i++) S[i].erase(S[i].begin()+j);
                W--;
                update = true;
                break;
            }
        }
    }

    for (string &s : S) cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
