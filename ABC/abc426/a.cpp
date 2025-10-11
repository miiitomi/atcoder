#include <bits/stdc++.h>
using namespace std;

vector<string> S = {"Ocelot", "Serval", "Lynx"};

int main() {
    string X, Y;
    cin >> X >> Y;
    int a = distance(S.begin(), find(S.begin(), S.end(), X));
    int b = distance(S.begin(), find(S.begin(), S.end(), Y));

    if (a >= b) cout << "Yes\n";
    else cout << "No\n";
}
