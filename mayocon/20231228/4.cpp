// https://atcoder.jp/contests/abc301/tasks/abc301_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S;
    ll N, K;
    cin >> S >> N;
    K = S.size();

    ll ans = 0;
    for (ll i = 0; i < K; i++) {
        if (S[K-1-i] == '1') {
            ans += (1LL << i);
        }
    }

    if (ans > N) {
        cout << -1 << endl;
        return 0;
    }

    for (ll i = K-1; i >= 0; i--) {
        if (S[K-1-i] == '?') {
            ll tmp = ans + (1LL << i);
            if (tmp <= N) ans = tmp;
        }
    }

    cout << ans << endl;
}
