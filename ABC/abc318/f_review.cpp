#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> X(N), L(N);
    for (int i = 0; i < N; i++) cin >> X[i];
    for (int i = 0; i < N; i++) cin >> L[i];

    vector<ll> S;
    S.reserve(2*N*N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ll k = X[i] + L[j];
            S.push_back(k);
            k = X[i] - L[j] - 1;
            S.push_back(k);
        }
    }
    sort(S.begin(), S.end());

    ll ans = 0;
    for (int i = 1; i < (int)S.size(); i++) {
        ll k = S[i];
        vector<ll> T(N);
        for (int j = 0; j < N; j++) T[j] = abs(X[j] - k);
        sort(T.begin(), T.end());
        bool can_get = true;
        for (int j = 0; j < N; j++) {
            if (T[j] > L[j]) can_get = false;
        }
        if (can_get) ans += S[i] - S[i-1];
    }

    cout << ans << endl;
}
