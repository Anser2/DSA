#include <iostream>
#include <chrono>  // High-precision timing
using namespace std;
using namespace std::chrono;

class factorial_series {
public:
    unsigned long long factorial_iteratively(int n) {
        if (n == 0) return 1;
        unsigned long long fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }

    unsigned long long factorial_recursively(int n) {
        if (n == 0 || n == 1) return 1;
        return n * factorial_recursively(n - 1);
    }
};

int main() {
    double iterative_times[10], recursive_times[10];
    int n = 0;

    for (int i = 0; i < 10; i++) {
        n += 100;  // Increase step size to 100 for noticeable time differences
        factorial_series fact;

        // Measure Iterative Time
        auto start = high_resolution_clock::now();
        fact.factorial_iteratively(n);
        auto end = high_resolution_clock::now();
        iterative_times[i] = duration<double>(end - start).count();

        // Measure Recursive Time
        start = high_resolution_clock::now();
        fact.factorial_recursively(n);
        end = high_resolution_clock::now();
        recursive_times[i] = duration<double>(end - start).count();
    }

    cout << "Iterative times: ";
    for (int i = 0; i < 10; i++) {
        cout << iterative_times[i] << " ";
    }
    cout << endl;

    cout << "Recursive times: ";
    for (int i = 0; i < 10; i++) {
        cout << recursive_times[i] << " ";
    }
    cout << endl;
}
