// https://atcoder.jp/contests/abc306/tasks/abc306_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll N, K, Q;
    cin >> N >> K >> Q;

    vector<ll> A(N, 0);
    multiset<ll> U, L;
    ll tmp = 0;
    for (int k = 0; k < K; k++) U.insert(0);
    for (int k = 0; k < N-K; k++) L.insert(0);
    vector<ll> ans;

    while (Q--) {
        ll x, y;
        cin >> x >> y;
        x--;

        ll a = A[x];
        A[x] = y;
        if (a >= *U.begin()) {
            U.erase(U.find(a));
            U.insert(y);
            tmp = tmp - a + y;
        } else {
            L.erase(L.find(a));
            L.insert(y);
        }

        if (!L.empty() && *U.begin() < *L.rbegin()) {
            ll s = *U.begin(), t = *L.rbegin();
            tmp = tmp + t - s;
            U.erase(U.find(s));
            U.insert(t);
            L.erase(L.find(t));
            L.insert(s);
        }

        ans.push_back(tmp);
    }

    for (ll a : ans) {
        cout << a << "\n";
    }
}
