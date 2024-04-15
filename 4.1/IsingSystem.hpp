#ifndef ISINGSYSTEM_HPP
#define ISINGSYSTEM_HPP

#include "IsingSpinOnLattice.hpp"
#include <vector>
#include <cmath>

class IsingSystem {
protected:
    const double J;
    const int n_spins;
    const long long maxrep_state;
    std::vector<IsingSpinOnLattice> spin;

public:
    IsingSystem(const int n_spins_spec);
    virtual ~IsingSystem();
    
    void set_dim(int dim);
    std::vector<int> _spin_position(const int site_idx) const;
    std::vector<int> _spin_NN(const int site_idx) const;
    int _spin_NN(const int site_idx, const int bond_idx) const;

    double _J() const;
    int _n_spins() const;
    long long _maxrep_state() const;

    int _sz(const int site_idx) const;
    void set_up_spin(const int site_idx);
    void set_dw_spin(const int site_idx);
    void set_spin(const int site_idx, int s_spec);
    void flip_spin(const int site_idx);

    void set_state_by_code(long long rep_state);
    void set_state(const std::vector<bool> state);
    double eval_Mz() const;
    double eval_energy_1D() const;

};

#endif // ISINGSYSTEM_HPP
