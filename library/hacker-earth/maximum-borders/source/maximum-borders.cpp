#include "maximum-borders.h"
#include <iostream>

using namespace std;

//int main() {
int process(istream &cin, ostream &cout) {
    int t, n, m, max;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        max = 0;
        cin >> n >> m;
        int innerMax = 0;
        for (int i = 0; i < n; i++) {
            bool inside = false;
            string str;
            cin >> str;
            if (innerMax > max)
                max = innerMax;
            innerMax = 0;
            for (auto &c : str) {
                if (inside) {
                    if (c == '#')
                        innerMax++;
                    else {
                        inside = false;
                        if (innerMax > max)
                            max = innerMax;
                        innerMax = 0;
                    }
                } else {
                    if (c == '#') {
                        inside = true;
                        innerMax++;
                    }
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}
