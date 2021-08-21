#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = (int)S.size();
    int K;
    cin >> K;
    K--;
    int S_kaijo = 1;
    for (int k = 1; k <= (int)S.size(); k++) S_kaijo *= k;

    unordered_set<string> se;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) nums[i] = i;

    do {
        string st = "";
        for (int i = 0; i < N; i++) st += S[nums[i]];
        se.insert(st);
    } while (next_permutation(nums.begin(), nums.end()));

    vector<string> v((int)se.size());
    int i = 0;
    for (string st : se) {
        v[i] = st;
        i++;
    }
    sort(v.begin(), v.end());
    cout << v[K] << endl;
}
