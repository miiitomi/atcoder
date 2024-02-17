// https://atcoder.jp/contests/abc227/tasks/abc227_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K, A;
    cin >> N >> K >> A;
    A--;

    for (int k = 1; k <= K; k++) {
        if (k == K) cout << A+1 << endl;
        A = (A+1) % N;
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
