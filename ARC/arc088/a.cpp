#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll X, Y;
    cin >> X >> Y;
    int ans = 1;
    ll now = X;
    while (2 * now <= Y) {
        ans++;
        now = 2 * now;
    }
    cout << ans << endl;
}
