// https://atcoder.jp/contests/abc193/tasks/abc193_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    set<ll> S;
    for (ll a = 2; a * a <= N; a++) {
        ll x = a*a;
        while (x <= N) {
            S.insert(x);
            x *= a;
        }
    }
    cout << N - (int)S.size() << endl;
}
