#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    ll x=0, y=0;
    while (N % 2 == 0) {
        N /= 2;
        x++;
    }
    while (N % 3 == 0) {
        N /= 3;
        y++;
    }

    if (N == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
