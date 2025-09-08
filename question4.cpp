#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

// Struct definition
struct TaylorTerm {
    int order;      // power of x (like 1, 3, 5, ...)
    double coeff;   // coefficient = (-1)^n / (2n+1)!
    double value;   // coeff * x^order
};

// Print functions (given by professor)
void print_taylor_term(int index, int order, double coeff, double value) {
    cout << "Term[" << index << "]: "
         << "order=" << order << ", "
         << "coeff=" << coeff << ", "
         << "value=" << value << "\n";
}

void print_taylor_result(const char* function_name, double x,
                         int terms, double approximation) {
    cout << "Approximation of " << function_name
         << "(x) at x=" << x
         << " with " << terms << " terms: "
         << approximation << "\n";
}

// Helper function to compute factorial
long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) fact *= i;
    return fact;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening " << argv[1] << endl;
        return 1;
    }

    double x;
    int N;
    input >> x >> N;  // read input (x and number of terms)

    TaylorTerm terms[N];  // array of terms
    double approximation = 0.0;

    for (int n = 0; n < N; n++) {
        int order = 2 * n + 1;
        double coeff = pow(-1, n) / factorial(order);
        double value = coeff * pow(x, order);

        terms[n] = {order, coeff, value};

        // Print this term
        print_taylor_term(n, order, coeff, value);

        approximation += value;
    }

    // Print final approximation
    print_taylor_result("sin", x, N, approximation);

    return 0;
}
