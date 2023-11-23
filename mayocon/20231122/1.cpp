// https://atcoder.jp/contests/abc156/tasks/abc156_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];

    int ans = 2e+9;
    for (int p = 1; p <= 100; p++) {
        int tmp = 0;
        for (int x : X) tmp += (x - p)*(x - p);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
