// https://atcoder.jp/contests/abc117/tasks/abc117_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<ll>> B(41, vector<ll>(2, 0));
    for (int l = 0; l < 41; l++) {
        for (ll a : A) {
            if (a & (1LL << l)) B[l][1]++;
            else B[l][0]++;
        }
    }
    ll S = 0, L = 40;
    while (L >= 0 && !(K & (1LL << L))) {
        S += (1LL << L) * B[L][1];
        L--;
    }

    ll ans = -1;

    for (; L >= 0; L--) {
        if (K & (1LL << L)) {
            ll tmp = S + (1LL << L) * B[L][1];
            for (ll l = 0; l < L; l++) {
                tmp += (1LL << l) * max(B[l][0], B[l][1]);
            }
            ans = max(ans, tmp);
        }
        if (K & (1LL << L)) S += (1LL << L) * B[L][0];
        else S += (1LL << L) * B[L][1];
    }

    ans = max(ans, S);

    cout << ans << endl;
}
