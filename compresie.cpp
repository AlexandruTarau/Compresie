#include <bits/stdc++.h>
using namespace std;

class Task {
 public:
    /* Function that runs the code */
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n, m;
    vector<int> a;
    vector<int> b;

    /* Reading function */
    void read_input() {
        ifstream fin("compresie.in");
        fin >> n;

        for (int i = 0, elem; i < n; i++) {
            fin >> elem;
            a.push_back(elem);
        }

        fin >> m;

        for (int i = 0, elem; i < m; i++) {
            fin >> elem;
            b.push_back(elem);
        }
        fin.close();
    }

    /* Function that calculates the result */
    int get_result() {
        int sum1 = a[0], sum2 = b[0];
        int i = 0, j = 0, k = 0;
        /* sum1 - sum of adjacent numbers of vector a
         * sum2 - sum of adjacent numbers of vector b
         */

        // Loop until at least one vector of numbers has been explored entirely
        while (i < n && j < m) {
            // If the sums are equal we move on to the next numbers
            if (sum1 == sum2) {
                k++; i++; j++;
                sum1 = a[i]; sum2 = b[j];
            } else if (sum1 < sum2) {
                // Continue only in vector a and add to the sum
                i++;
                sum1 += a[i];
            } else {
                // Continue only in vector b and add to the sum
                j++;
                sum2 += b[j];
            }
        }

        /* If k hasn't been updated or either vector hasn't been fully explored,
        there is no answer */
        if (k == 0 || i != n || j != m) {
            k = -1;
        }
        return k;
    }

    /* Printing function */
    void print_output(int result) {
        ofstream fout("compresie.out");
        fout << result;
        fout.close();
    }
};

int main() {
    auto* task = new (nothrow) Task();
    if (!task) {
        cerr << "new failed: WTF are you doing? Throw your PC!\n";
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
