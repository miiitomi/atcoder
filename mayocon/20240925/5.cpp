// https://atcoder.jp/contests/abc159/tasks/abc159_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    ll ans = INF;
    for (ll st = 0; st < (1 << (H-1)); st++) {
        vector<vector<int>> v;
        vector<int> tmp;
        ll cnt = 0;
        for (int i = 0; i < H; i++) {
            tmp.push_back(i);
            if (st & (1 << i)) {
                v.push_back(tmp);
                tmp = {};
                cnt++;
            }
        }
        v.push_back(tmp);
        tmp.assign(v.size(), 0);
        for (int j = 0; j < W; j++) {
            vector<int> tmp2(v.size(), 0);
            for (int k = 0; k < (int)v.size(); k++) {
                for (int i : v[k]) tmp2[k] += (S[i][j] == '1');
            }
            bool ok = true;
            for (int k = 0; k < (int)v.size(); k++) {
                if (tmp2[k] > K) {
                    cnt = INF;
                    ok = false;
                    break;
                }
                if (tmp[k] + tmp2[k] > K) {
                    ok = false;
                }
            }
            if (cnt == INF) break;
            if (!ok) {
                cnt++;
                swap(tmp, tmp2);
            } else {
                for (int k = 0; k < (int)v.size(); k++) tmp[k] += tmp2[k];
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
