#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    string ans = "Yes";

    for (int i = 0; i < S.size(); i++) {
        if (i % 2 == 0) {
            if (isupper(S.at(i))) {
                ans = "No";
                break;
            }
        } else {
            if (islower(S.at(i))) {
                ans = "No";
                break;
            }
        }
    }
    cout << ans << endl;
}