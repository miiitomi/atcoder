// https://atcoder.jp/contests/abc186/tasks/abc186_f
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
    int H, W, M;
    cin >> H >> W >> M;
    vector<ll> X(M), Y(M);
    for (int i = 0; i < M; i++) {
        cin >> X[i] >> Y[i];
        X[i]--;
        Y[i]--;
    }

    ll ans = 1;
    priority_queue<pair<int,int>> Q;
    vector<ll> reachable(H, W);
    ll reachable_x = H;
    for (int i = 0; i < M; i++) {
        reachable[X[i]] = min(reachable[X[i]], Y[i]);
        if (Y[i] == 0) reachable_x = min(reachable_x, X[i]);
    }

    for (int x = 1; x < reachable_x; x++) {
        ans += reachable[x];
        Q.push(make_pair(reachable[x]-1, x));
    }

    reachable.assign(W, H);
    ll reachable_y = W;
    for (int i = 0; i < M; i++) {
        reachable[Y[i]] = min(reachable[Y[i]], X[i]);
        if (X[i] == 0) reachable_y = min(reachable_y, Y[i]);
    }

    BIT bit(H);
    for (int y = reachable_y-1; y >= 1; y--) {
        while (!Q.empty() && Q.top().first >= y) {
            ll x = Q.top().second;
            Q.pop();
            bit.add(x, 1);
        }
        ans += reachable[y] - bit.sum(0, reachable[y]);
    }

    cout << ans << endl;
}
