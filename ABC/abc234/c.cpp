#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll K;
    cin >> K;
    string ans = "";
    while (K > 0) {
        if (K & 1) {
            ans = '2' + ans;
        } else {
            ans = '0' + ans;
        }
        K = (K >> 1LL);
    }
    cout << ans << endl;
}
