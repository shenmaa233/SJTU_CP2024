#ifndef ISINGSYSTEM_SQUARE_HPP
#define ISINGSYSTEM_SQUARE_HPP

#include "IsingSystem.hpp"
#include <vector>

class IsingSystem_Square : public IsingSystem {
protected:
    std::vector<int> system_size;

    // Utility functions for nearest neighbors and lattice coordinates
    

    void setup_NN();

public:
    IsingSystem_Square(const std::vector<int>& system_size_spec);
    virtual ~IsingSystem_Square();
    int site_index(const std::vector<int>& lattice_coordinate) const;
    std::vector<int> lattice_coordinate(int site_index) const;
    std::vector<int> shift_pos_x(const std::vector<int>& r_spec) const;
    std::vector<int> shift_pos_y(const std::vector<int>& r_spec) const;
    std::vector<int> shift_neg_x(const std::vector<int>& r_spec) const;
    std::vector<int> shift_neg_y(const std::vector<int>& r_spec) const;
    int NN(const int site_idx, const int bond_idx) const;
    double eval_energy() const;
};

#endif // ISINGSYSTEM_SQUARE_HPP
