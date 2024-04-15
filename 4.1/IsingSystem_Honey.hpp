#ifndef ISINGSYSTEM_HONEY_HPP
#define ISINGSYSTEM_HONEY_HPP

#include <vector>
#include "IsingSystem.hpp"

class IsingSystem_Honey : public IsingSystem {
private:
    std::vector<int> system_size;
    std::vector<double> beta;
    std::vector<double> _exact_energy_Z_results; // Declare the missing variable
    std::vector<double> _exact_energy_q_results; // Declare the missing variable
    std::vector<double> _exact_energy_q_sq_results; // Declare the missing variable
    std::vector<double> _exact_magz_Z_results; // Declare the missing variable
    std::vector<double> _exact_magz_q_sq_results; // Declare the missing variable

public:
    IsingSystem_Honey(const std::vector<int>& system_size_spec);
    IsingSystem_Honey(const std::vector<int>& system_size_spec, const std::vector<double>& beta_spec);
    virtual ~IsingSystem_Honey();

    double _exact_energy_Z(std::size_t beta_idx) const;
    double _exact_energy_q(std::size_t beta_idx) const;
    double _exact_energy_q_sq(std::size_t beta_idx) const;
    double _exact_magz_Z(std::size_t beta_idx) const;
    double _exact_magz_q_sq(std::size_t beta_idx) const;

    void setup_NN();
    int site_index(const std::vector<int>& lattice_coordinate) const;
    std::vector<int> lattice_coordinate(int site_index) const;
    std::vector<int> shift_pos_x(const std::vector<int>& r_spec) const;
    std::vector<int> shift_pos_y(const std::vector<int>& r_spec) const;
    std::vector<int> shift_neg_x(const std::vector<int>& r_spec) const;
    std::vector<int> shift_neg_y(const std::vector<int>& r_spec) const;
    int NN(const int site_idx, const int bond_idx) const;
    double eval_energy() const;
    double weight_unnormalized(double beta) const;
    void exactly_evaluate_given();
    void normalize_direct();
    void exactly_evaluate(const long long& rep_state);
    void exactly_evaluate(const std::vector<bool>& state);
    void exact();
    void print_exact() const;
};

#endif // ISINGSYSTEM_HONEY_HPP