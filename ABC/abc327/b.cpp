#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull pow(ull a) {
    ull ans = 1;
    for (int i = 0; i < a; i++) ans *= a;
    return ans;
}

int main() {
    ull B;
    cin >> B;
    for (ull a = 1; pow(a) <= B; a++) {
        if (pow(a) == B) {
            cout << a << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
