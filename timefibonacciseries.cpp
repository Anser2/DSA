#include <iostream>
#include <chrono>  // Better timing accuracy
using namespace std;
using namespace std::chrono;

class fibonacci_series {
public:
    int calculate_sum_iteratively(int n) {
        if (n == 0) return 0;
        int current = 1, previous_sum = 0;
        for (int i = 1; i < n; i++) {
            int temp = current;
            current = current + previous_sum;
            previous_sum = temp;
        }
        return current;
    }

    int calculate_sum_recursively(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return calculate_sum_recursively(n - 1) + calculate_sum_recursively(n - 2);
    }
};

int main() {
    double iterative_times[10], recursive_times[10];
    int n = 0;

    for (int i = 0; i < 10; i++) {
        n += 5;
        fibonacci_series fib;

        // Measure Iterative Time
        auto start = high_resolution_clock::now();
        fib.calculate_sum_iteratively(n);
        auto end = high_resolution_clock::now();
        iterative_times[i] = duration<double>(end - start).count();  // Convert to seconds

        // Measure Recursive Time
        start = high_resolution_clock::now();
        fib.calculate_sum_recursively(n);
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
