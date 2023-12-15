// https://atcoder.jp/contests/abc228/tasks/abc228_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N = (1LL << 20);
    vector<ll> A(N, -1);
    set<ll> S;
    for (int i = 0; i < N; i++) S.insert(i);
    ll Q;
    cin >> Q;
    while (Q--) {
        ll t, x;
        cin >> t >> x;
        if (t == 1) {
            ll h = x % N;
            auto iter = S.lower_bound(h);
            if (iter == S.end()) iter = S.lower_bound(0);
            ll i = *iter;
            S.erase(iter);
            A[i] = x;
        } else {
            ll i = x % N;
            cout << A[i] << endl;
        }
    }
}
