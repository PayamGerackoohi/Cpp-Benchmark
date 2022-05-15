#include "will-she-accept-him.h"

using namespace std;

void success(ostream &cout, bool success) {
    if (success)
        cout << "Love you too" << endl;
    else
        cout << "We are only friends" << endl;
}

bool isSubSequenceOf(const string &s1, const string &s2) {
    auto sourceLength = s1.length();
    auto targetLength = s2.length();
    if (sourceLength == 0)
        return true;
    int i = 0;
    for (int j = 0; i < sourceLength && j < targetLength; j++)
        if (s1[i] == s2[j])
            i++;
    return i == sourceLength;
}

//int main() {
int process(istream &cin, ostream &cout) {
    int t;
    cin >> t;
    if (t > 0) {
        for (auto i = 0; i < t; i++) {
            string arr[2];
            cin >> arr[0] >> arr[1];
            success(cout, isSubSequenceOf(arr[0], arr[1]));
        }
    }
    return 0;
}
