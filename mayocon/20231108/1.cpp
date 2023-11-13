// https://atcoder.jp/contests/abc296/tasks/abc296_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    for (ll a : A) {
        auto iter = lower_bound(A.begin(), A.end(), X + a);
        if (iter != A.end() && *iter == X + a) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
