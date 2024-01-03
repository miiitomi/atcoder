// https://atcoder.jp/contests/abc151/tasks/abc151_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, M;
    cin >> N >> K >> M;
    int S = 0;
    for (int i = 0; i < N-1; i++) {
        int a;
        cin >> a;
        S += a;
    }
    int T = N * M - S;
    if (T <= 0) cout << 0 << endl;
    else if (T <= K) cout << T << endl;
    else cout << -1 << endl;
}
