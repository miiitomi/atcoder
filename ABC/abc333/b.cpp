#include <bits/stdc++.h>
using namespace std;

string S = "ABCDE";

int main() {
    char s, t, u, v;
    cin >> s >> t >> u >> v;
    int x = abs((int)S.find(s) - (int)S.find(t)), y = abs((int)S.find(u) - (int)S.find(v));
    x = min(x, 5-x);
    y = min(y, 5-y);

    if (x == y) cout << "Yes" << endl;
    else cout << "No" << endl;
}
