// https://atcoder.jp/contests/abc115/tasks/abc115_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for (int i = 0; i < N; i++) cin >> h[i];
    sort(h.begin(), h.end());

    int ans = (int)2e+9 + 10;
    for (int i = 0; i < N; i++) {
        int tmp = - h[i];
        int j = i + K - 1;
        if (j >= N) break;
        tmp += h[j];
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
