// https://atcoder.jp/contests/abc248/tasks/abc248_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> B(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        B[a].push_back(i);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--; x--;
        auto iter = lower_bound(B[x].begin(), B[x].end(), l);
        auto iter2 = lower_bound(B[x].begin(), B[x].end(), r + 1);
        cout << distance(iter, iter2) << "\n";
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
