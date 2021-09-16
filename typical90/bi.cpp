#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    vector<int> V(200000, -1);
    int top = 100000-1;
    int bottom = 100000;
    vector<int> ans;
    for (int i = 0; i < Q; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            V[top] = x;
            top--;
        } else if (t == 2) {
            V[bottom] = x;
            bottom++;
        } else {
            int y = V[top + x];
            ans.push_back(y);
        }
    }
    for (int y : ans) {
        cout << y << endl;
    }
}
