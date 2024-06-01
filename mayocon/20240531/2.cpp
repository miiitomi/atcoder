// https://atcoder.jp/contests/abc329/tasks/abc329_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> cnt(N, 0);
    int idx = 0, v = 0;

    while (M--) {
        int a;
        cin >> a;
        a--;
        cnt[a]++;
        if (cnt[a] > v) {
            v = cnt[a];
            idx = a;
        } else if (cnt[a] == v && a < idx) {
            idx = a;
        }

        cout << idx+1 << "\n";
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
