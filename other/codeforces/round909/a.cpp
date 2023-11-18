#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    if (N % 3 == 0) cout << "Second" << endl;
    else cout << "First" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
