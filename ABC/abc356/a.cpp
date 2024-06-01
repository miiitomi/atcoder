#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, L, R;
    cin >> N >> L >> R;
    for (int x = 1; x < L; x++) cout << x << " ";
    for (int x = R; x >= L; x--) cout << x << " ";
    for (int x = R+1; x <= N; x++) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
