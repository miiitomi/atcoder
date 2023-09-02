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
            S.push_back(X[i] + L[j]);
            S.push_back(X[i] - L[j] - 1);
        }
    }
    sort(S.begin(), S.end());

    ll ans = 0;
    for (int i = 1; i < (int)S.size(); i++) {
        ll k = S[i];
        vector<ll> d(N);
        for (int j = 0; j < N; j++) {
            d[j] = abs(X[j] - k);
        }
        sort(d.begin(), d.end());
        bool can = true;
        for (int j = 0; j < N; j++) {
            if (d[j] > L[j]) {
                can = false;
                break;
            }
        }
        if (!can) continue;
        ans += S[i] - S[i-1];
    }

    cout << ans << endl;
}
