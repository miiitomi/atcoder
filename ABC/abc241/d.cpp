#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int Q;
    cin >> Q;

    map<ll, ll> M;

    for (int i = 0; i < Q; i++) {
        ll n, x, k;
        cin >> n >> x;

        if (n == 1) {
            M[x]++;
            continue;
        }

        cin >> k;
        auto iter = M.lower_bound(x);

        if (n == 2) {
            if (iter->first > x || iter == M.end()) {
                if (iter == M.begin()) {
                    cout << -1 << endl;
                    continue;
                }
                iter--;
            }

            bool b = true;
            while (iter->second < k) {
                k -= iter->second;
                if (iter == M.begin()) {
                    b = false;
                    break;
                }
                iter--;
            }

            if (b) cout << iter->first << endl;
            else cout << -1 << endl;
        }

        if (n == 3) {
            if (iter == M.end()) {
                cout << -1 << endl;
                continue;
            }

            bool b = true;
            while (iter->second < k) {
                k -= (iter->second);
                iter++;
                if (iter == M.end()) {
                    b = false;
                    break;
                }
            }
            if (b) cout << iter->first << endl;
            else cout << -1 << endl;
        }
    }
}
