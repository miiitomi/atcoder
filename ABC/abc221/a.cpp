#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int d = A - B;
    long long ans = 1LL;
    for (int i = 0; i < d; i++) {
        ans = ans * 32LL;
    }
    cout << ans << endl;
}
