#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int K;
    cin >> K;
    string A, B;
    cin >> A >> B;
    ll a = 0;
    ll b = 0;
    ll p = 1;
    for (int i = (int)A.size()-1; i >= 0; i--) {
        a += (ll)(A[i] - '0') * p;
        p *= K;
    }
    p = 1;
    for (int i = (int)B.size()-1; i >= 0; i--) {
        b += (ll)(B[i] - '0') * p;
        p *= K;
    }
    cout << a * b << endl;
}
