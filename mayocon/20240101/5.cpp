// https://atcoder.jp/contests/abc174/tasks/abc174_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;
vector<ll> A;

bool can_lower_than_x(ll x) {
    ll cnt = 0;
    for (ll a : A) {
        ll b = (a + x - 1) / x;
        cnt += b-1;
    }
    return cnt <= K;
}

int main() {
    cin >> N >> K;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll left = 0, right = 1e+9;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        if (can_lower_than_x(mid)) right = mid;
        else left = mid;
    }
    cout << right << endl;
}
