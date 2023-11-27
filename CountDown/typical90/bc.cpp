#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, P, Q;
    cin >> N >> P >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    bool done = false;
    vector<int> v{0, 1, 2, 3, 4};

    int cnt = 0;

    while (!done) {
        ll tmp = 1;
        for (int i : v) tmp = tmp * A[i] % P;

        if (tmp == Q) cnt++;

        done = true;
        for (int k = 4; k >= 0; k--) {
            if (v[k] < N-5+k) {
                done = false;
                v[k]++;
                for (int j = k+1; j < 5; j++) v[j] = v[j-1] + 1;
                break;
            }
        }
    }

    cout << cnt << endl;
}
