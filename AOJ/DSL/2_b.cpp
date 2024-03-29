// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
// 平方分割による解法
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, Q;
    cin >> N >> Q;
    int n = sqrt(N) + 1;
    vector<ll> A(N, 0);
    vector<ll> B(n, 0);

    for (int q = 0; q < Q; q++) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            x--;
            A[x] += y;
            B[x/n] += y;
        } else {
            x--;
            ll ans = 0;
            if (x/n == y/n) {
                for (int i = x; i < y; i++) ans += A[i];
            } else {
                while (x % n != 0) {
                    ans += A[x];
                    x++;
                }
                while (x / n != y / n) {
                    ans += B[x / n];
                    x += n;
                }
                while (x != y) {
                    ans += A[x];
                    x++;
                }
            }
            cout << ans << endl;
        }
    }
}
