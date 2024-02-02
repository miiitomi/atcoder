// https://atcoder.jp/contests/abc330/tasks/abc330_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, L, R;
    cin >> N >> L >> R;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int a : A) {
        if (a < L) cout << L << " ";
        else if (a <= R) cout << a << " ";
        else cout << R << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
