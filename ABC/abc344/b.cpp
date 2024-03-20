#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> A;
    int a = -1;
    while (a != 0) {
        cin >> a;
        A.push_back(a);
    }
    reverse(A.begin(), A.end());
    for (int a : A) cout << a << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
