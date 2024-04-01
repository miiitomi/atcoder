// https://atcoder.jp/contests/abc146/tasks/abc146_a
#include <bits/stdc++.h>
using namespace std;

vector<string> weeks{"SUN","MON","TUE","WED","THU","FRI","SAT"};

void solve() {
    string S;
    cin >> S;
    int i = distance(weeks.begin(), find(weeks.begin(), weeks.end(), S));
    cout << 7 - i << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
