#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    string m = to_string(n);
    for (int i = 0; i < m.size(); i++) {
        if (m.at(i) == '7') {
            return 0;
        }
    }
    while (n > 0) {
        if (n % 8 == 7) {
            return 0;
        }
        n /= 8;
    }
    return 1;
}

int main() {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += f(i);
    }
    cout << ans << endl;
}