#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A, B;
    cin >> A >> B;
    
    if (A % B == 0) {
        cout << A / B << endl;
    } else {
        cout << A / B + 1 << endl;
    }
}
