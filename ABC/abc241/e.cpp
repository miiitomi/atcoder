#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    set<ll> S;
    vector<ll> V, W;
    ll X = 0;
    V.push_back(X);
    S.insert(X);
    W.push_back(X);

    while (true) {
        X = X + A[X % N];
        if (S.count(X % N)) break;
        S.insert(X % N);
        V.push_back(X % N);
        W.push_back(X);
    }

    ll idx = 0;
    while (V[idx] != (X % N)) {
        idx++;
        K--;
        if (K == 0) {
            cout << W[idx] << endl;
            return 0;
        }
    }

    ll sum = X - W[idx];
    X = W[idx];

    if ((ll)V.size() - idx <= K) {
        X += (sum * (K / ((ll)V.size() - idx)));
        K %= ((ll)V.size() - idx);
    }

    ll idx_old = idx;
    while (K > 0) {
        idx++;
        K--;
    }
    X += W[idx] - W[idx_old];
    cout << X << endl;
}
