#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    swap(S[a], S[b]);
    cout << S << endl;
}
