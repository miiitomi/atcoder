#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> S(8);
    for (int i = 0; i < 8; i++) cin >> S[i];
    int now = -1;

    bool yes = true;
    for (int s : S) {
        if (s < now) yes = false;
        if (s < 100 || s > 675) yes = false;
        if (s % 25 != 0) yes = false;
        now = s;
    }

    if (yes) cout << "Yes" << endl;
    else cout << "No" << endl;
}
