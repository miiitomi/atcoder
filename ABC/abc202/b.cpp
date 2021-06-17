#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.size();
    string ans = "";

    for (int i = 0; i < n; i++) {
        if (S.at(i) == '6') S.at(i) = '9';
        else if (S.at(i) == '9') S.at(i) = '6';

        ans = S.at(i) + ans;
    }

    cout << ans << endl;
}