#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll &N, vector<ll> &A) {
    ll ans = 0;
    map<ll,ll> mp;
    for (int i = 0; i < N; i++) {
        ll a = A[i];
        if ((a % 5) == 0) {
            ans += mp[(a/5)*7] * mp[(a/5)*3];
        }
        mp[a]++;
    }
    return ans;
}


int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll ans = f(N, A);
    reverse(A.begin(), A.end());
    ans += f(N, A);
    cout << ans << "\n";
}
