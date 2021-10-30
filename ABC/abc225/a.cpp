#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    vector<int> V;
    V.push_back(0);
    V.push_back(1);
    V.push_back(2);
    set<string> X;

    do {
        string x = "";
        for (int i = 0; i < 3; i++) {
            x = x + S[V[i]];
        }
        X.insert(x);
    } while (next_permutation(V.begin(), V.end()));

    cout << (int)X.size() << endl;
}
