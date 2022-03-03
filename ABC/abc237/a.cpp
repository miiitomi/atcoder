#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    ll x = 1LL;
    for (int i = 0; i < 31; i++) {
        x *= 2LL;
    }

    if (N >= -x && N < x) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
