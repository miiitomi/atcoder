// https://atcoder.jp/contests/abc274/tasks/abc274_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(2*N+2, 0);
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        A[2*i] = A[a]+1;
        A[2*i+1] = A[a]+1;
    }
    for (int i = 1; i <= 2*N+1; i++) cout << A[i] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
