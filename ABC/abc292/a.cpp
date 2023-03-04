#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    for (char s : S) {
        int x = (char)(s - 'a');
        cout << (char)('A' + x);
    }
    cout << endl;
}
