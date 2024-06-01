// https://atcoder.jp/contests/abc127/tasks/abc127_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll m = 0;
ll v = 0;
ll c = 0;
priority_queue<ll, vector<ll>, greater<ll>> R;
priority_queue<ll> L;

void solve() {
    ll Q;
    cin >> Q;
    while (Q--) {
        ll k;
        cin >> k;
        if (k == 1) {
            ll a, b;
            cin >> a >> b;
            c += b;
            if ((int)L.size() == 0 && (int)R.size() == 0) {
                m = a;
                L.push(a);
            } else {
                if (L.top() < a) {
                    v += abs(m - a);
                    R.push(a);
                } else {
                    L.push(a);
                    v += abs(m-a);
                }

                if (L.size() > R.size()+1) {
                    ll p = L.top();
                    L.pop();
                    ll q = L.top();
                    R.push(p);
                    v += -(p-q) * L.size() + (p-q)*R.size();
                    m = q;
                } else if (L.size() < R.size()) {
                    ll p = R.top();
                    v += -(p-m)*R.size() + (p-m)*L.size();
                    R.pop();
                    L.push(p);
                    m = p;
                }
            }
        } else {
            cout << m << " " << v+c << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
