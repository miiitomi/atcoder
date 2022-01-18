#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    ll a = X[N/2];
    ll b = Y[N/2];
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(a - X[i]) + abs(b - Y[i]);
    }
    cout << ans << endl;
}
