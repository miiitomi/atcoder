// https://atcoder.jp/contests/abc199/tasks/abc199_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    int a = *max_element(A.begin(), A.end()), b = *min_element(B.begin(), B.end());
    if (a > b) cout << 0 << "\n";
    else cout << (b - a + 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
