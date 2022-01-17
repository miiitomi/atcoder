#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll N) {
    ll x = N;
    ll y = 0;
    while (N > 0) {
        y += N % 10;
        N /= 10;
    }
    return (x + y) % 100000;
}

int main() {
    ll N, K;
    cin >> N >> K;

    unordered_map<ll, ll> M;
    M[N] = 0;
    ll cycle;

    for (ll counter = 1; K > 0; counter++) {
        N = f(N);
        K--;
        if (K == 0) {
            cout << N << endl;
            return 0;
        } else if (M.count(N)) {
            cycle = counter - M[N];
            break;
        } else {
            M[N] = counter;
        }
    }

    K %= cycle;
    for (;K>0;K--) N = f(N);
    cout << N << endl;
}
