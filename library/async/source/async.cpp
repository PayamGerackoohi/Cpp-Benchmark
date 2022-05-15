//
// Created by Payam Gerackoohi on 11.05.22.
//

#include "async.h"
#include "math-util.h"

using namespace std;

void async_sample() {
    int localVariable = add(10, 20);
//    int localVariable = 100;

    cout << "Hi" << endl;
    thread th{[=]() {
        int n = 5;
        while (n-- > 0) {
            this_thread::sleep_for(chrono::seconds(1));
            cout << "variable: " << localVariable << ", n: " << n << endl;
        }
    }};
    cout << "Bye" << endl;

    this_thread::sleep_for(chrono::milliseconds(2'500));
    th.detach();
//    th.join();

    cout << "End of Main" << endl;
}
