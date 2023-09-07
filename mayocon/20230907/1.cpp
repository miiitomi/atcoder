// https://atcoder.jp/contests/abc116/tasks/abc116_b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a;
    cin >> a;
    set<ll> S;

    int i = 1;
    while (true) {
        if (S.count(a)) {
            cout << i << endl;
            return 0;
        } else {
            S.insert(a);
            i++;
            if (a % 2 == 0) a /= 2;
            else a = (3*a) + 1;
        }
    }
}
