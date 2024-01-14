// https://atcoder.jp/contests/abc201/tasks/abc201_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(3, 0);
    for (int i = 0; i < 3; i++) cin >> v[i];
    sort(v.begin(), v.end());

    do {
        if (v[2] - v[1] == v[1] - v[0]) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << "No" << endl;
}
