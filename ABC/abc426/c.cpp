#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> v(N+1, 1);
    v[0] = 0;
    int i = 1;
    while (Q--) {
        int x, y, ans = 0;
        cin >> x >> y;
        while (i <= x) {
            ans += v[i];
            v[i] = 0;
            i++;
        }
        cout << ans << "\n";
        v[y] += ans;
    }
}
