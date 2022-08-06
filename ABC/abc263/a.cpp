#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> V(13, 0);
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        a--;
        V[a]++;
    }

    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());

    if (V[0] == 3 && V[1] == 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
