// https://atcoder.jp/contests/abc057/tasks/abc057_d
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

vector<vector<ll>> C(51, vector<ll>(51, 0));

int main() {
    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) C[i][j] = 1;
            else C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }

    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<ll> u = v;
    u.erase(unique(u.begin(), u.end()), u.end());
    vector<ll> c((int)u.size(), 0);
    for (ll x : v) c[distance(u.begin(), lower_bound(u.begin(),u.end(), x))]++;

    vector<ll> V;
    while (c.back() < A) {
        for (int k = 0; k < c.back(); k++) V.push_back(u.back());
        u.pop_back();
        A -= c.back();
        B -= c.back();
        c.pop_back();
    }

    ll ans = 0;
    if (V.size() == 0) {
        for (int k = A; k <= min(c.back(), B); k++) ans += C[c.back()][k];
        cout << fixed << setprecision(15) << (double)u.back() << endl << ans << endl;
    } else {
        ans += C[c.back()][A];
        while (A--) V.push_back(u.back());
        double mean = 0.0;
        for (ll x : V) mean += x;
        mean /= (double)V.size();
        cout << fixed << setprecision(15) << mean << endl << ans << endl;
    }
}
