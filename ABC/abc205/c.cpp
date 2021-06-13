#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    string ans = ">";

    if (C % 2 == 0) {
        if (abs(A) > abs(B)) ans = ">";
        else if (abs(A) == abs(B)) ans = "=";
        else ans = "<";
    } else {
        if (A < B) ans = "<";
        else if (A == B) ans = "=";
        else ans = ">";
    }
    cout << ans << endl;
}