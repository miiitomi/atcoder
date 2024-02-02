// https://atcoder.jp/contests/abc304/tasks/abc304_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int W, H, N;
    cin >> W >> H >> N;
    vector<int> p(N), q(N);
    for (int i = 0; i < N; i++) cin >> p[i] >> q[i];
    int A, B;
    cin >> A;
    vector<int> a{0}, b{0};
    for (int i = 0; i < A; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    A++;
    cin >> B;
    for (int i = 0; i < B; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    B++;

    map<pair<int,int>, int> mp;
    for (int i = 0; i < N; i++) {
        int s = distance(a.begin(), lower_bound(a.begin(), a.end(), p[i])) - 1;
        int t = distance(b.begin(), lower_bound(b.begin(), b.end(), q[i])) - 1;
        mp[make_pair(s, t)] += 1;
    }

    int cnt = 0, maxv = -1, minv = 1e+9;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        cnt++;
        maxv = max(maxv, iter->second);
        minv = min(minv, iter->second);
    }

    if (cnt == A*B) cout << minv << " " << maxv << "\n";
    else cout << 0 << " " << maxv << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
