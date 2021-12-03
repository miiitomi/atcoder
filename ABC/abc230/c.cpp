#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, A, B, P, Q, R, S;

bool f(ll i, ll j) {
    ll k1 = i - A;
    ll k2 = j - B;
    if (k1 != k2) return false;

    if (max(1 - A, 1 - B) <= k1 && k1 <= min(N-A, N-B)) return true;
    return false;
}

bool g(ll i, ll j) {
    ll k1 = i - A;
    ll k2 = B - j;

    if (k1 != k2) return false;

    if (max(1 - A, B - N) <= k1 && k1 <= min(N - A, B - 1)) return true;
    return false;
}

int main() {
    cin >> N >> A >> B;
    cin >> P >> Q >> R >> S;

    for (ll i = P; i <= Q; i++) {
        for (ll j = R; j <= S; j++) {
            if (f(i, j) || g(i, j)) cout << "#";
            else cout << ".";
        }
        cout << endl;
    }
}
