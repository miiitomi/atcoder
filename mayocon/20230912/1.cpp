// https://atcoder.jp/contests/abc171/tasks/abc171_a
#include <bits/stdc++.h>
using namespace std;

string A ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    char a;
    cin >> a;

    if (find(A.begin(), A.end(), a) != A.end()) cout << "A" << endl;
    else cout << "a" << endl;
}
