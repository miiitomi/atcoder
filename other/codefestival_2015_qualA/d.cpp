#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f(ll k, int N, int M, vector<ll> &X) {
    ll now = 0;
    for (int i = 0; i < M; i++) {
        if (k < X[i] - now) return false;
        if (X[i] <= now) now = X[i] + k + 1;
        else now = max(max(X[i], k - X[i] + 2*now), (k + X[i] + now) / 2) + 1;
        if (now >= N) return true;
    }
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> X(M);
    for (int i = 0; i < M; i++) {
        cin >> X[i];
        X[i]--;
    }

    ll left = -1;
    ll right = 1e10;

    while (right - left > 1) {
        ll mid = (left + right) / 2;
        if (f(mid, N, M, X)) right = mid;
        else left = mid;
    }
    cout << right << endl;
}
