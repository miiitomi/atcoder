#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    vector<char> V((int)S.size());
    for (int i = 0; i < (int)S.size(); i++) V[i] = S[i];
    sort(V.begin(), V.end());
    for (int i = 0; i < (int)S.size(); i++) cout << V[i];
    cout << endl;
}
