// https://atcoder.jp/contests/abc251/tasks/abc251_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int W;
    cin >> W;
    vector<int> A;
    for (int x = 1; x <= 99; x++) A.push_back(x);
    for (int x = 1; x <= 99; x++) A.push_back(100 * x);
    for (int x = 1; x <= 99; x++) A.push_back(10000 * x);
    A.push_back(1000000);

    cout << A.size() << "\n";
    for (int a : A) cout << a << " ";
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
