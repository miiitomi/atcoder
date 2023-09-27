// https://atcoder.jp/contests/abc321/tasks/abc321_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll subtree(ll N, ll S, ll K) {
    if (K < 0) return 0;
    ll left = S, right = S;
    while (K > 0) {
        left = 2*left;
        right = 2*right + 1;
        K--;
        if (left > N) return 0;
    }
    return min(right, N) - left + 1;
}


void solve() {
    ll N, S, K;
    cin >> N >> S >> K;

    ll ans = subtree(N, S, K);

    while (true) {
        if (S == 1 || K == 0) break;
        if (K == 1) {
            ans++;
            break;
        }

        ans += subtree(N, S ^ 1, K-2);
        S /= 2;
        K--;
        if (K == 0) {
            ans++;
            break;
        }
    }

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
