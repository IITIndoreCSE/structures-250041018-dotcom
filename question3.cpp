#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// Struct for a point
struct Point {
    double x;
    double y;
};

// Required output function
void print_point_rotation(double x_before, double y_before,
                          double theta, double x_after, double y_after) {
    cout << "Before rotation: (x=" << x_before << ", y=" << y_before << ")\n";
    cout << "After rotation (θ=" << theta << " rad): "
         << "(x=" << x_after << ", y=" << y_after << ")\n";
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

    // Read input values
    Point p;
    double theta;
    input >> p.x >> p.y >> theta;

    // Compute rotated coordinates
    double x_after = p.x * cos(theta) - p.y * sin(theta);
    double y_after = p.x * sin(theta) + p.y * cos(theta);

    // Print results
    print_point_rotation(p.x, p.y, theta, x_after, y_after);

    return 0;
}
