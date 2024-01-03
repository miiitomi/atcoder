// https://atcoder.jp/contests/abc319/tasks/abc319_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S(N+1, '-');

    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= 9; j++) {
            if (N % j != 0) continue;
            if (i % (N/j) == 0) {
                S[i] = '0' + j;
                break;
            }
        }
    }

    cout << S << endl;
}
