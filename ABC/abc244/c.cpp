#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<bool> V(2*N + 2, false);
    V[0] = true;

    for (int i = 0; i < N; i++) {
        int idx = 0;
        while (V[idx]) idx++;
        cout << idx << endl;
        V[idx] = true;

        int x;
        cin >> x;
        V[x] = true;
    }
    int idx = 0;
    while (V[idx]) idx++;
    cout << idx << endl;
    return 0;
}
