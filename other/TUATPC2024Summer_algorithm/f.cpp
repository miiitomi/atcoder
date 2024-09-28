#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll M;
    cin >> M;
    vector<ll> v;
    for (ll x = (ll)1e+5; x >= 2; x--) {
        ll y = x*(x-1)/2;
        ll k = M/y;
        for (ll i = 0; i < k; i++) v.push_back(x);
        M %= y;
    }
    vector<ll> A;
    ll K = (ll)1e+5;
    reverse(v.begin(), v.end());
    ll p = 2;
    while (!v.empty()) {
        ll x = v.back();
        v.pop_back();
        while (K > x) {
            A.push_back(1);
            K--;
        }
        A.push_back(p);
        p++;
    }
    while (K > 0) {
        A.push_back(1);
        K--;
    }
    cout << A.size() << "\n";
    for (int i = 0; i < (int)A.size(); i++) {
        cout << A[i];
        if (i == (int)A.size()-1) cout << "\n";
        else cout << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
