#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> P(N-1), T(N-1);
    for (int i = 0; i < N-1; i++) cin >> P[i] >> T[i];

    vector<ll> V(840);
    for (int _q = 0; _q < 840; _q++) {
        ll q = _q;
        ll start = q;

        q += X;
        for (int i = 0; i < N-1; i++) {
            if (q % P[i] != 0) q += P[i] - (q % P[i]);
            q += T[i];
        }
        q += Y;

        V[_q] = q - start;
    }

    int Q;
    cin >> Q;
    for (int _t = 0; _t < Q; _t++) {
        ll q;
        cin >> q;
        cout << V[q % 840] + q << endl;
    }
}
