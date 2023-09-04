// https://atcoder.jp/contests/abc278/tasks/abc278_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> last_updated(N, -1);
    int last_update_time = -1;
    ll last_update_value = -1;

    int Q;
    cin >> Q;
    for (int t = 0; t < Q; t++) {
        int k;
        cin >> k;
        if (k == 1) {
            ll x;
            cin >> x;
            last_update_value = x;
            last_update_time = t;
        } else if (k == 2) {
            int i;
            ll x;
            cin >> i >> x;
            i--;
            if (last_update_time > last_updated[i]) {
                A[i] = last_update_value;
                last_updated[i] = last_update_time;
            }
            A[i] += x;
        } else {
            int i;
            cin >> i;
            i--;
            if (last_update_time > last_updated[i]) {
                A[i] = last_update_value;
                last_updated[i] = last_update_time;
            }
            cout << A[i] << endl;
        }
    }
}
