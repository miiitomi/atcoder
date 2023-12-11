// https://atcoder.jp/contests/abc141/tasks/abc141_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    ll sum = 0;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    vector<ll> v;
    for (ll a : A) {
        while (a > 0) {
            ll b = a / 2;
            v.push_back(a - b);
            a = b;
        }
    }
    sort(v.begin(), v.end());

    while (M--) {
        ll x = v.back();
        v.pop_back();
        sum -= x;

        if (v.empty()) break;
    }

    cout << sum << endl;
}
