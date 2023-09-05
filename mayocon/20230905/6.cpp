// https://atcoder.jp/contests/abc236/tasks/abc236_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> c(1), b;
int main() {
    int N;
    cin >> N;
    for (int i = 1; i < (1 << N); i++) {
        int p;
        cin >> p; 
        c.push_back(p);
        b.push_back(i);
    }
    sort(b.begin(), b.end(), [] (const ll &i, const ll &j) {return c[i] < c[j];});

    vector<bool> computable((1 << N), false);
    ll ans = 0;
    for (ll x : b) {
        if (!computable[x]) {
            ans += c[x];
            computable[x] = true;
            for (ll y = 1; y < (1 << N); y++) {
                if (computable[y]) {
                    computable[x^y] = true;
                }
            }
        }
    }

    cout << ans << endl;
}
