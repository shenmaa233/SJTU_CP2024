#ifndef ISINGSPINONLATTICE_HPP
#define ISINGSPINONLATTICE_HPP

#include "IsingSpin.hpp"
#include <vector>

class IsingSpinOnLattice : public IsingSpin {
protected:
    std::vector<int> position; // Stores the position of the spin on the lattice
    std::vector<int> NN; // Nearest neighbors indices

public:
    IsingSpinOnLattice();
    virtual ~IsingSpinOnLattice();
    
    void set_dim(int dim);
    std::vector<int> _position() const;
    std::vector<int> _NN() const;
    int _NN(const unsigned int bond_idx) const;
    void set_NN(const int bond_idx, const int site_idx);
};

#endif // ISINGSPINONLATTICE_HPP
