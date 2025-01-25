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
    ll hl = INF, hr = -1, wl = INF, wr = -1;
    ll cnt_black = 0, cnt_hatena = 0;
    vector<string> S(H);
    vector<pair<ll,ll>> hatena;
    for (ll h = 0; h < H; h++) {
        cin >> S[h];
        for (ll j = 0; j < W; j++) {
            if (S[h][j] == '#') {
                cnt_black++;
                hl = min(hl, h);
                hr = max(hr, h);
                wl = min(wl, j);
                wr = max(wr, j);
            } else if (S[h][j] == '?') {
                hatena.push_back({h, j});
            }
        }
    }

    if (cnt_black == 0) {
        if (hatena.empty()) cout << "No\n";
        else cout << "Yes\n";
        return;
    }

    for (auto p : hatena) {
        auto [i,j] = p;
        if (hl <= i && i <= hr && wl <= j && j <= wr) {
            S[i][j] = '#';
        } else {
            S[i][j] = '.';
        }
    }

    for (int i = hl; i <= hr; i++) {
        for (int j = wl; j <= wr; j++) {
            if (S[i][j] == '.') {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
