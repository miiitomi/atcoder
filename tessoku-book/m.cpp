#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll ans = 0;
    int r = 1;
    for (int l = 0; l < N; l++) {
        while (r < N && A[r] - A[l] <= K) {
            r++;
        }
        ans += r - l - 1;
    }
    cout << ans << endl;
}
