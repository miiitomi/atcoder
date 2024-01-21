#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct BIT {
    int n;
    vector<ll> data;

    BIT(int _n) {
        n = _n + 1;
        data.assign(n, 0);
    }

    void add(int i, ll x) {
        // Add x to a[i] (0-indexed).
        for (int idx = i + 1; idx < n; idx += (idx & -idx)) {
            data[idx] += x;
        }
    }

    ll sum(int i) {
        // compute sum of a[i] with i in [0, i)
        ll ans = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            ans += data[idx];
        }
        return ans;
    }

    ll sum(int a, int b) {
        // compute sum of a[i] with i in [a, b)
        return sum(b) - sum(a);
    }
};

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    int ans = 1e+9;

    for (int h = 0; h < H; h++) {
        BIT bit1(W), bit2(W);
        for (int w = 0; w < W; w++) {
            if (S[h][w] == 'o') bit1.add(w, 1);
            else if (S[h][w] == '.') bit2.add(w, 1);
        }

        for (int w = 0; w+K <= W; w++) {
            int x = bit1.sum(w, w+K), y = bit2.sum(w, w+K);
            if (x + y == K) {
                ans = min(ans, y);
            }
        }
    }

    for (int w = 0; w < W; w++) {
        BIT bit1(H), bit2(H);
        for (int h = 0; h < H; h++) {
            if (S[h][w] == 'o') bit1.add(h, 1);
            else if (S[h][w] == '.') bit2.add(h, 1);
        }

        for (int h = 0; h+K <= H; h++) {
            int x = bit1.sum(h, h+K), y = bit2.sum(h, h+K);
            if (x + y == K) {
                ans = min(ans, y);
            }
        }        
    }

    if (ans < 1e+8) cout << ans << endl;
    else cout << -1 << endl;
}
