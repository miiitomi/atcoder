// https://atcoder.jp/contests/abc330/tasks/abc330_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K;
vector<ll> X, Y;

ll min_cost(ll W, vector<ll> &v) {
    ll left = v[0], right = v[0] + W;
    int l = 0, r = N-1;
    ll tmp = 0;
    while (r >= 0 && v[r] > right) {
        tmp += v[r] - right;
        r--;
    }
    r++;
    while (l <= N-1 && v[l] <= left) l++;

    ll ans = tmp;

    while (r <= N-1) {
        ll d = min(v[l] - left, v[r]-right);
        tmp += (l - (N-r))*d;
        ans = min(ans, tmp);
        left += d;
        right += d;
        while (l <= N-1 && v[l] <= left) l++;
        while (r <= N-1 && v[r] <= right) r++;
    }

    return ans;
}

void solve() {
    cin >> N >> K;
    X.resize(N);
    Y.resize(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    ll left = -1, right = 1e+9;

    while (right - left > 1) {
        ll m = (right + left) / 2;
        ll tmp = min_cost(m, X) + min_cost(m, Y);
        if (tmp <= K) right = m;
        else left = m;
    }

    cout << right << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
