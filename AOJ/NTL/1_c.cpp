#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

ll lcm(vector<ll> &a) {
    ll ans = a[0];
    for (int i = 1; i < (int)a.size(); i++) {
        ans = lcm(ans, a[i]);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << lcm(a) << endl;
}
