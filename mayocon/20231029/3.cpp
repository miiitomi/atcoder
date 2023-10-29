// https://atcoder.jp/contests/abc189/tasks/abc189_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int ans = -1;
    for (int i = 0; i < N; i++) {
        int tmp = 1e+6;
        for (int j = i; j < N; j++) {
            tmp = min(tmp, A[j]);
            ans = max(ans, (j-i+1)*tmp);
        }
    }

    cout << ans << endl;
}
