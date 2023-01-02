#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int r = 0;
    ll sum = 0;
    ll ans = 0;
    for (int l = 0; l < N; l++) {
        while (r < N && sum + A[r] <= K) {
            sum += A[r];
            r++;
        }
        ans += r - l;
        sum -= A[l];
    }

    cout << ans << endl;
}
