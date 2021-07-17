#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int warui;
    for (int i = 0; i < N; i++) {
        if (S.at(i) == '1') {
            warui = i;
            break;
        }
    }

    if (warui % 2 == 0) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }

}
