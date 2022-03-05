#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

char f(ll t, ll k) {
    if (t == 0) return S[k];

    if (k == 0) {
        ll x = (int)(S[0] - 'A');
        x = (x + t) % 3;
        if (x == 0) return 'A';
        else if (x == 1) return 'B';
        else return 'C';
    }

    ll x = (int)(f(t-1, k/2) - 'A');
    if (k % 2 == 1) x = (x + 2) % 3;
    else x = (x + 1) % 3;

    if (x == 0) return 'A';
    else if (x == 1) return 'B';
    else return 'C';
}

int main() {
    cin >> S;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        ll t, k;
        cin >> t >> k;
        k--;
        cout << f(t, k) << endl;
    }
}
