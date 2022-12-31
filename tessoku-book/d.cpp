#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> ans(10, 0);

    for (int i = 0; i < 10; i++) {
        ans[i] = N % 2;
        N = N >> 1;
    }

    for (int j = 9; j >= 0; j--) {
        cout << ans[j];
    }
    cout << endl;
}
