#include <bits/stdc++.h>
using namespace std;

vector<string> V{"ACE","BDF","CEG","DFA","EGB","FAC","GBD"};

int main() {
    string S;
    cin >> S;
    if (count(V.begin(), V.end(), S)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
