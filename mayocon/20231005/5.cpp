// https://atcoder.jp/contests/abc306/tasks/abc306_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;

    multiset<ll> U, L;
    for (int k = 0; k < K; k++) U.insert(0);
    for (int k = 0; k < N-K; k++) L.insert(0);
    ll tmp = 0;
    vector<ll> A(N, 0);

    for (int q = 0; q < Q; q++) {
        int x;
        ll y;
        cin >> x >> y;
        x--;

        ll a = A[x];
        if (U.count(a)) {
            tmp = tmp - a + y;
            U.erase(U.find(a));
            U.insert(y);
        } else {
            L.erase(L.find(a));
            L.insert(y);
        }

        if (K < N) {
            ll s = *U.begin();
            auto iter = L.end();
            iter--;
            ll t = *iter;

            if (s < t) {
                tmp = tmp + t - s;
                U.erase(U.find(s));
                U.insert(t);
                L.erase(L.find(t));
                L.insert(s);
            }
        }

        A[x] = y;
        cout << tmp << endl;
    }
}
