#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string ans = "AGC0";
    if (N < 10) {
        cout << ans << 0 << N << endl;
    } else if (N < 42) {
        cout << ans << N << endl;
    } else {
        cout << ans << N + 1 << endl;
    }
}
