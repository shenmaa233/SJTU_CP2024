#ifndef ISINGSYSTEM_SQUARE_HPP
#define ISINGSYSTEM_SQUARE_HPP

#include "IsingSystem.hpp"
#include <vector>

class IsingSystem_Square : public IsingSystem {
protected:
    std::vector<int> system_size;
    std::vector<double> beta;
    std::vector<double> _exact_energy_Z_results;
    std::vector<double> _exact_energy_q_results;
    std::vector<double> _exact_energy_q_sq_results;
    std::vector<double> _exact_magz_Z_results;
    std::vector<double> _exact_magz_q_sq_results;
    // Utility functions for nearest neighbors and lattice coordinates
    void setup_NN();

public:
    IsingSystem_Square(const std::vector<int>& system_size_spec);
    IsingSystem_Square(const std::vector<int> &system_size_spec, const std::vector<double> &beta_spec);
    virtual ~IsingSystem_Square();
    int site_index(const std::vector<int>& lattice_coordinate) const;
    std::vector<int> lattice_coordinate(int site_index) const;
    std::vector<int> shift_pos_x(const std::vector<int>& r_spec) const;
    std::vector<int> shift_pos_y(const std::vector<int>& r_spec) const;
    std::vector<int> shift_neg_x(const std::vector<int>& r_spec) const;
    std::vector<int> shift_neg_y(const std::vector<int>& r_spec) const;
    int NN(const int site_idx, const int bond_idx) const;
    double eval_energy() const;
    double weight_unnormalized(double beta) const;
    // Functions related to exact evaluation, might require definitions depending on the test case
    void exactly_evaluate_given();
    void exactly_evaluate(const std::vector<bool>& state);
    void exactly_evaluate(const long long& rep_state);
    void exact();
    void normalize_direct();
    void print_exact() const;
    double _exact_energy_Z(std::size_t beta_idx) const;
    double _exact_energy_q(std::size_t beta_idx) const;
    double _exact_energy_q_sq(std::size_t beta_idx) const;
    double _exact_magz_Z(std::size_t beta_idx) const;
    double _exact_magz_q_sq(std::size_t beta_idx) const;
};

#endif // ISINGSYSTEM_SQUARE_HPP
