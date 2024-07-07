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
    for (ll s = 0; s < (1LL << (H-1)); s++) {
        vector<vector<int>> V;
        vector<int> v;
        for (int i = 0; i < H; i++) {
            v.push_back(i);
            if (s & (1 << i)) {
                V.push_back(v);
                v = {};
            }
        }
        V.push_back(v);
        ll tmp = V.size()-1;
        vector<ll> cnt(V.size(), 0);
        bool is_ok = true;
        for (int j = 0; j < W; j++) {
            vector<ll> tmp_cnt(V.size(), 0);
            for (int k = 0; k < (int)V.size(); k++) {
                for (int i : V[k]) tmp_cnt[k] += (S[i][j] == '1');
                if (tmp_cnt[k] > K) is_ok = false;
            }
            if (!is_ok) break;
            bool is_over = false;
            for (int k = 0; k < (int)V.size(); k++) {
                cnt[k] += tmp_cnt[k];
                if (cnt[k] > K) is_over = true;
            }
            if (is_over) {
                tmp++;
                swap(cnt, tmp_cnt);
            }
        }
        if (is_ok) {
            ans = min(ans, tmp);
        }
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
