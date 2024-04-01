#include "IsingSpinOnLattice.hpp"

IsingSpinOnLattice::IsingSpinOnLattice() : NN({-1}) {
    // Constructor initialization list initializes NN with a single element (-1)
}

IsingSpinOnLattice::~IsingSpinOnLattice() {
    // Destructor - nothing to do here because vector takes care of its own memory
}

void IsingSpinOnLattice::set_dim(int dim) {
    position.assign(dim, 0);
}

std::vector<int> IsingSpinOnLattice::_position() const {
    return position;
}

std::vector<int> IsingSpinOnLattice::_NN() const {
    return NN;
}

int IsingSpinOnLattice::_NN(const unsigned int bond_idx) const {
    if (bond_idx < NN.size()) {
        return NN[bond_idx];
    } else {
        return -1; // Indicates an invalid index
    }
}

void IsingSpinOnLattice::set_NN(const int bond_idx, const int site_idx) {
    if (bond_idx >= NN.size()) {
        NN.resize(bond_idx + 1, -1); // Resize and fill new slots with -1
    }
    NN[bond_idx] = site_idx; // Set the nearest neighbor index at the specified bond
}
