#include "holiday-season.h"

using namespace std;

//int main() {
int process(istream &cin, ostream &cout) {
    string str;
    long long n, aCount[26], ans = 0;
    for (auto &i : aCount)
        i = 0;
    cin >> n >> str;
    for (int i = 0; i < n; i++) { // a or b
        // b
        long long acMatch = 0;
        for (int j = i + 1; j <= n; j++) { // c or d
            // d
            if (str[i] == str[j]) {
                ans += acMatch;
            }
            // c
            acMatch += aCount[str[j] - 'a'];
        }
        // a
        aCount[str[i] - 'a']++;
    }
    cout << ans << endl;
    return 0;
}
