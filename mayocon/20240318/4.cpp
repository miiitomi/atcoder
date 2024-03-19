// https://atcoder.jp/contests/abc221/tasks/abc221_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    map<int,int> mp;
   for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        mp[a]++;
        mp[a+b]--;
    }
    vector<int> cnt(N+1, 0);
    int tmp_i = 0;
    int tmp = 0;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        int ntmpi = iter->first;
        cnt[tmp] += (ntmpi - tmp_i);
        mp[ntmpi] += tmp;
        tmp = mp[ntmpi];
        swap(tmp_i, ntmpi);
    }

    for (int k = 1; k <= N; k++) {
        cout << cnt[k];
        if (k != N) cout << " ";
        else cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
