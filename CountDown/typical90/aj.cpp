#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        a[i] = x + y;
        b[i] = x - y;
    }
    vector<ll> s = a, t = b;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for (int q = 0; q < Q; q++) {
        int i;
        cin >> i;
        i--;
        ll ans = -1;
        ans = max(ans, abs(s[0] - a[i]));
        ans = max(ans, abs(s[N-1] - a[i]));
        ans = max(ans, abs(t[0] - b[i]));
        ans = max(ans, abs(t[N-1] - b[i]));
        cout << ans << endl;
    }
}
