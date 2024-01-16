// https://atcoder.jp/contests/abc263/tasks/abc263_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(N, 0);
    for (int i = 1; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }

    int x = N-1, ans =0;
    while (x != 0) {
        x = P[x];
        ans++;
    }

    cout << ans << endl;
}
