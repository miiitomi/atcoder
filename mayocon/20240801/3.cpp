// https://atcoder.jp/contests/abc300/tasks/abc300_c
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
    ll N = min(H, W);
    vector<ll> cnt(N+1, 0);
    vector<ll> dx{1, 1, -1, -1}, dy{1, -1, 1, -1};
    auto is_in = [&](int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;};
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            if (S[x][y] == '.') continue;
            int tmp = 0;
            vector<int> a(4, x), b(4, y);
            for (int k = 1; k <= N; k++) {
                bool is_ok = true;
                for (int l = 0; l < 4; l++) {
                    a[l] += dx[l];
                    b[l] += dy[l];
                    if (!is_in(a[l], b[l]) || S[a[l]][b[l]] == '.') {
                        is_ok = false;
                        break;
                    }
                }
                if (is_ok) tmp++;
                else break;
            }
            cnt[tmp]++;
        }
    }

    for (int k = 1; k <= N; k++) cout << cnt[k] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
