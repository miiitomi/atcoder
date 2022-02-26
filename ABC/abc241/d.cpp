#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int Q;
    cin >> Q;
    multiset<ll> A;

    for (int i = 0; i < Q; i++) {
        ll n, x, k;
        cin >> n >> x;

        if (n == 1) {
            A.insert(x);
        } else if (n == 2) {
            cin >> k;
            auto iter = A.upper_bound(x);
            bool exists = true;
            for (int j = 0; j < k; j++) {
                if (iter == A.begin()) {
                    exists = false;
                    break;
                }
                iter--;
            }
            if (exists) cout << *iter << endl;
            else cout << -1 << endl;
        } else if (n == 3) {
            cin >> k;
            auto iter = A.lower_bound(x);
            for (int j = 0; j < k-1; j++) {
                if (iter == A.end()) break;
                iter++;
            }
            if (iter == A.end()) cout << -1 << endl;
            else cout << *iter << endl;
        }
    }
}
