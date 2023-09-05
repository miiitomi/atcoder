// https://atcoder.jp/contests/abc123/tasks/abc123_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    for (int i = 0; i < X; i++) cin >> A[i];
    for (int i = 0; i < Y; i++) cin >> B[i];
    for (int i = 0; i < Z; i++) cin >> C[i];

    vector<ll> S;
    S.reserve(X*Y);
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            S.push_back(A[i] + B[j]);
        }
    }
    sort(S.begin(), S.end());

    // K個目の値 v を探す.
    ll left = 0;
    ll right = (ll)1e+15;
    while (right - left > 1) {
        ll mid = (right + left) / 2;
        ll cnt = 0;
        for (ll c : C) {
            ll target = mid - c;
            auto iter = lower_bound(S.begin(), S.end(), target);
            cnt += distance(iter, S.end());
        }
        if (cnt >= K) left = mid;
        else right = mid;
    }

    vector<ll> V;
    V.reserve(K);
    for (ll c : C) {
        auto iter = lower_bound(S.begin(), S.end(), left - c + 1);
        int i = distance(S.begin(), iter);
        while (i < (int)S.size()) {
            V.push_back(c + S[i]);
            i++;
        }
    }

    while (V.size() < K) V.push_back(left);
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    for (ll v : V) cout << v << endl;
}
