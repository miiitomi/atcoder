// https://atcoder.jp/contests/abc308/tasks/abc308_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N = 8;
    vector<int> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    bool ok = true;
    for (int i = 0; i < N; i++) {
        if (!(100 <= S[i] && S[i] <= 675)) ok = false;
        if (S[i] % 25 != 0) ok = false;
        if (i != 0 && !(S[i-1] <= S[i])) ok = false;
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
