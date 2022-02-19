#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll X;
    cin >> X;
    if (X >= 0) cout << X / 10 << endl;
    else if ((-X) % 10 == 0) cout << X / 10 << endl;
    else cout << (X / 10) - 1 << endl;
}
