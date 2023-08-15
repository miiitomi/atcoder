#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (c % 2) a++;

    int x = min(a, b);
    a -= x;
    b -= x;

    if (a == 0) cout << "Second" << endl;
    else cout << "First" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();    
}
