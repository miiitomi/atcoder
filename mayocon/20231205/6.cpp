// https://atcoder.jp/contests/abc297/tasks/abc297_g
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, L, R;
    cin >> N >> L >> R;
    vector<ll> A(N);
    ll x = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] %= (R+L);
        x ^= (A[i]/L);
    }

    if (x == 0) cout << "Second" << endl;
    else cout << "First" << endl;
}
