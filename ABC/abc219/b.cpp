#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> S(3);
    for (int i = 0; i < 3; i++) cin >> S[i];
    string T;
    cin >> T;
    for (int i = 0; i < (int)T.size(); i++) {
        cout << S[(int)(T[i]-'0')-1];
    }
    cout << endl;
}
