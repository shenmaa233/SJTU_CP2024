#include <iostream>
#include <vector>

#include "IsingSystem_Square.hpp"


template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "{";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i < v.size() - 1) {
            os << ", ";
        }
    }
    os << "}";
    return os;
}

int main(int argc, char** argv) {
    
    const std::vector<int> system_size = {6, 6}; 
    IsingSystem_Square model(system_size);

    std::cout << "Number of spins: " << model._n_spins() << std::endl;
    std::cout << "Interaction constant J: " << model._J() << std::endl;

    
    const std::vector<int> lattice_coordinate = {3, 4};
    std::cout << "Site index for lattice coordinate (3, 4): " 
              << model.site_index(lattice_coordinate) << std::endl;
              
    std::cout << "Lattice coordinate for site index 27: " 
              << model.lattice_coordinate(27) << std::endl;
    
    
    long long state_code = 777; 
    model.set_state_by_code(state_code); 
    double mz = model.eval_Mz(); 
    double energy = model.eval_energy_1D(); 

    std::cout << "Configuration #" << state_code << ":" << std::endl;
    std::cout << "Total Magnetization (M): " << mz << std::endl;
    std::cout << "Total Energy (E): " << energy << std::endl;

    return 0;
}
