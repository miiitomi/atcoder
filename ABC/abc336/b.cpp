#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    while (N % 2 == 0) {
        ans++;
        N /= 2;
    }
    cout << ans << endl;
}
