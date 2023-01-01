#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll prints(vector<ll> &A, ll T) {
    ll res = 0;
    for (ll a : A) {
        res += T / a;
    }
    return res;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll left = 0;
    ll right = 1 + 1e+9;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        ll res = prints(A, mid);
        if (res >= K) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << endl;
}
