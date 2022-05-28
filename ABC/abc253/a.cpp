#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    int b = v[1];
    sort(v.begin(), v.end());
    if (b == v[1]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
