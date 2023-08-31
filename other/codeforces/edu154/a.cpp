#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    int i = distance(S.begin(), find(S.begin(), S.end(), '1'));
    int j = distance(S.begin(), find(S.begin(), S.end(), '3'));

    if (i < j) cout << "13" << endl;
    else cout << "31" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
