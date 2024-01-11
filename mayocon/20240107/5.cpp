// https://atcoder.jp/contests/abc270/tasks/abc270_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll left = 0, right = K+1;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        ll cnt = 0;
        for (int i = 0; i < N; i++) cnt += min(mid, A[i]);
        if (cnt <= K) left = mid;
        else right = mid;
    }

    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        ll x = min(left, A[i]);
        A[i] -= x;
        cnt += x;
    }
    K -= cnt;

    int tmp = 0;
    while (K > 0) {
        if (A[tmp] > 0) {
            K--;
            A[tmp]--;
        }
        tmp++;
    }

    for (ll a : A) cout << a << " ";
    cout << endl;
}
