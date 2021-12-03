#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    ll first = 1;
    ll k, left, right, mid;
    ll ans = 0;

    while (first < N + 1) {
        k = N / first;
        left = first;
        right = N + 1;
        while (right - left > 1) {
            mid = (left + right) / 2;
            if (N / mid < k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        ans += (right - first) * k;
        first = right;
    }
    cout << ans << endl;
}
