// https://atcoder.jp/contests/abc275/tasks/abc275_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, ll> M;

ll f(ll x) {
    if (M.count(x)) return M[x];
    if (x == 0) {
        M[x] = 1;
        return M[x];
    }
    M[x] = f(x/2) + f(x/3);
    return M[x];
}

int main() {
    ll N;
    cin >> N;
    cout << f(N) << endl;
}
