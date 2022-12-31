#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    string N;
    cin >> N;
    int k = N.size();

    int now = 1;
    for (int i = k-1; i >= 0; i--) {
        if (N[i] == '1') {
            ans += now;
        }
        now *= 2;
    }

    cout << ans << endl;
}
