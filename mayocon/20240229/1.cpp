// https://atcoder.jp/contests/abc236/tasks/abc236_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> cnt(N+1, 0);
    for (int i = 1; i <= 4*N-1; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    for (int i = 1; i <= N; i++) if (cnt[i] < 4) cout << i << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
