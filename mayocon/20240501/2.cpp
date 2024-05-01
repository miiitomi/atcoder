// https://atcoder.jp/contests/abc337/tasks/abc337_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> B(N+1, -1);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a == -1) B[0] = i+1;
        else B[a] = i+1;
    }

    int k = 0;
    while (B[k] != -1) {
        cout << B[k] << " ";
        k = B[k];
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
