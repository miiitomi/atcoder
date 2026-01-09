#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> cnt(N+1, 0);
    for (ll x = 1; x*x <= N; x++) {
        for (ll y = x+1; x*x + y*y <= N; y++) {
            cnt[x*x + y*y]++;
        }
    }
    vector<ll> ans;
    for (ll x = 1; x <= N; x++) {
        if (cnt[x] == 1) ans.push_back(x);
    }
    cout << ans.size() << "\n";
    for (ll x: ans) cout << x << " ";
    cout << "\n";
}
