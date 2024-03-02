
#include "inputgen.h"

void inputgen::generator(){

    double min_value = 1.0;
    double max_value = 5.0;

    // Seeding random number generator
    std::srand(std::time(0));
    std::ofstream outfile("input.txt");

    outfile << "10" << "\n";
    for(int i=0; i<10; i++){
        // Random floating point value
        double random_number = min_value + static_cast<double>(std::rand()) / RAND_MAX * (max_value - min_value);
        outfile << random_number << "\n";
    }

    outfile.close();

}