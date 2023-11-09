// https://atcoder.jp/contests/abc150/tasks/abc150_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

vector<mint> P(1e+6, 1);

int main() {
    for (int x = 1; x < 1e+6; x++) P[x] = P[x - 1] * 2;

    int N;
    cin >> N;
    vector<int> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(C.begin(), C.end());
    reverse(C.begin(), C.end());
    mint ans = 0;

    for (int r = 0; r < N; r++) {
        mint tmp = P[N-1] * C[r];
        if (r > 0) tmp += P[N-2] * C[r] * r;
        ans += tmp;
    }
    ans *= P[N];

    cout << ans.val() << endl;
}
