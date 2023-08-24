#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

void solve() {
    ull N;
    cin >> N;

    ull l = 1;
    ull r = 2LL * pow(10LL, 9LL);
    ull m = (r + l) / 2;

    while (r - l > 1) {
        m = (r + l) / 2;
        if ((m * (m-1)) / 2 > N) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << l + (N - (l*(l-1)/2)) << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
