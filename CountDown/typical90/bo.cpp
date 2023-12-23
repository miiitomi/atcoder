#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int K;
    string eight, nine;
    cin >> eight >> K;

    while (K--) {
        nine = "";
        ll x = 0, y = 1;
        while (eight.size() > 0) {
            x += y * (eight.back() - '0');
            eight.pop_back();
            y *= 8;
        }
        while (x > 0) {
            nine.push_back('0' + (x % 9));
            x /= 9;
        }
        reverse(nine.begin(), nine.end());
        for (char &c : nine) {
            if (c == '8') c = '5';
        }
        eight = nine;
        if (eight.size() == 0) eight = "0";
    }
    cout << eight << endl;
}
