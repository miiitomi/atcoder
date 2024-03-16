// https://atcoder.jp/contests/abc260/tasks/abc260_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    map<int, vector<int>> mp;
    vector<int> ans(N+1, -1);
    for (int i = 1; i <= N; i++) {
        int p;
        cin >> p;
        auto iter = mp.lower_bound(p);

        if (iter == mp.end()) {
            mp[p] = {p};
        } else {
            int q = iter->first;
            mp[p] = {};
            swap(mp[p], mp[q]);
            mp[p].push_back(p);
            mp.erase(q);
        }

        if ((int)mp[p].size() >= K) {
            for (int x : mp[p]) ans[x] = i;
            mp.erase(p);
        }
    }

    for (int i = 1; i <= N; i++) cout << ans[i] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
