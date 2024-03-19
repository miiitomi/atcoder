// https://atcoder.jp/contests/abc217/tasks/abc217_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
        Q[P[i]] = i;
    }

    for (int i = 0; i < N; i++) {
        cout << Q[i]+1;
        if (i == N-1) cout << "\n";
        else cout << " ";
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
