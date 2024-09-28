#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    sort(A.begin(), A.end());
    for (ll x = N; x >= 1; x--) {
        ll M = A.back()*x;
        if (M < sum) {
            M = sum;
            if (M % x != 0) M += (x - (M%x));
        }
        ll R = M-sum;
        if (R <= K) {
            cout << x << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
