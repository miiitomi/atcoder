#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    if (N >= 2008) cout << "Namiki Secondary School" << endl;
    else if (N >= 1984) cout << "Namiki High School" << endl;
    else cout << "None" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
