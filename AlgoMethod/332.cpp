#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A, B;
    cin >> A >> B;

    ll b = 0;
    while (b*b < B) b++;

    vector<bool> V(b+1, true);
    V[0] = false;
    V[1] = false;
    vector<bool> W(B-A+1, true);

    for (ll x = 2; x <= b; x++) {
        if (!V[x]) continue;

        for (ll y = 2*x; y <= b; y += x) V[y] = false;

        ll z = (A / x) * x;
        if (A % x != 0) z += x;
        while (z <= B) {
            if (z != x) W[z - A] = false;
            z += x;
        }
    }

    int ans = 0;
    for (int i = 0; i < (int)W.size(); i++) {
        if (W[i]) ans++;
    }

    cout << ans << endl;
}
