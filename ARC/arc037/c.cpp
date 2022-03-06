#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f(ll K, ll x, vector<ll> &a, vector<ll> &b) {
    ll counter = 0;
    for (ll y : a) {
        auto iter = upper_bound(b.begin(), b.end(), x / y);
        counter += distance(b.begin(), iter);
        if (counter >= K) return false;
    }
    return true;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++) 
    cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll left = 0;
    ll right = 1e18 + 1LL;

    while (right - left > 1) {
        ll mid = (left + right) / 2;
        if (f(K, mid, a, b)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << right << endl;
}
