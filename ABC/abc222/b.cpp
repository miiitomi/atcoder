#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, P;
    cin >> N >> P;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a < P) ans++;
    }
    cout << ans << endl;
}
