#include <iostream>
#include <fstream>
using namespace std;

// Struct definition
struct Sensor {
    int id;
    double temperature;
    double voltage;
};

// Required output function
void print_sensor(int index, int id, double temperature, double voltage) {
    cout << "Sensor[" << index << "]: "
         << "id=" << id << ", "
         << "temperature=" << temperature << ", "
         << "voltage=" << voltage << "\n";
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

    int num_sensors;
    input >> num_sensors;
    if (num_sensors > 10) num_sensors = 10; // limit for safety

    Sensor sensors[10];

    // Read sensors
    for (int i = 0; i < num_sensors; i++) {
        input >> sensors[i].id
              >> sensors[i].temperature
              >> sensors[i].voltage;
    }

    // Use a pointer to iterate instead of indexing
    Sensor* ptr = sensors;
    for (int i = 0; i < num_sensors; i++, ptr++) {
        print_sensor(i, ptr->id, ptr->temperature, ptr->voltage);
    }

    return 0;
}
