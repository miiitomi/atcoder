#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        ll N;
        cin >> N;
        for (ll x = 1; x <= N; x++) {
            if (N == x) {
                cout << x << endl;
            } else if (N % x != 0) {
                cout << x-1 << endl;
                break;
            }
        }
    }
}
