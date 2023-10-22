#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll A=a, C=1;
    for (int k = 0; k < b; k++) C *= c;

    if (A < C) cout << "Yes" << endl;
    else cout << "No" << endl;
}
