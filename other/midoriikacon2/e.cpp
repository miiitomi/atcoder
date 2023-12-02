#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> v(N, 0);
    for (int k = 0; k < K; k++) v[N-1-k] = 1;

    ll cnt = 0;
    do {
        ll S = 0;
        for (int i = 0; i < N; i++) {
            if (v[i] == 1LL) S += A[i];
        }
        if ((S % MOD) <= (S % 998)) cnt++;
    } while (next_permutation(v.begin(), v.end()));

    cout << (cnt % 998) << endl;
}
