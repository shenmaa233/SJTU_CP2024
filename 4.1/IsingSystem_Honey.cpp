#include "IsingSystem_Honey.hpp"
#include <iostream>
#include <vector>
#include "IsingSystem_Square.hpp"

IsingSystem_Honey::IsingSystem_Honey(const std::vector<int>& system_size_spec)
    : IsingSystem(system_size_spec[0] * system_size_spec[1]), system_size(system_size_spec) {
    setup_NN();
};

IsingSystem_Honey::IsingSystem_Honey(const std::vector<int>& system_size_spec, const std::vector<double>& beta_spec)
        : IsingSystem(system_size_spec[0] * system_size_spec[1]), system_size(system_size_spec), beta(beta_spec) {
        // 实现可以与原始构造函数相同，但还可以根据需要进行额外的初始化
        setup_NN();
        // 可以在这里添加使用beta进行的初始化代码
    }

IsingSystem_Honey::~IsingSystem_Honey() {

}

double IsingSystem_Honey::_exact_energy_Z(std::size_t beta_idx) const {
    return _exact_energy_Z_results[beta_idx];
}

double IsingSystem_Honey::_exact_energy_q(std::size_t beta_idx) const {
    return _exact_energy_q_results[beta_idx];
}

double IsingSystem_Honey::_exact_energy_q_sq(std::size_t beta_idx) const {
    return _exact_energy_q_sq_results[beta_idx];
}

// Define the missing variables
std::vector<double> _exact_energy_Z_results;
std::vector<double> _exact_energy_q_results;
std::vector<double> _exact_energy_q_sq_results;
std::vector<double> _exact_magz_Z_results;

double IsingSystem_Honey::_exact_magz_Z(std::size_t beta_idx) const {
    return _exact_magz_Z_results[beta_idx];
}

double IsingSystem_Honey::_exact_magz_q_sq(std::size_t beta_idx) const {
    return _exact_magz_q_sq_results[beta_idx];
}

void IsingSystem_Honey::setup_NN() {
    for (int site_idx = 0; site_idx < n_spins; ++site_idx) {
        std::vector<int> r = lattice_coordinate(site_idx);
        if( r[0] % 2 == 0 && r[1] % 2 == 0) {
            spin[site_idx].set_NN(0, site_index(shift_pos_x(r)));
            spin[site_idx].set_NN(1, site_index(shift_pos_y(r)));
            spin[site_idx].set_NN(2, site_index(shift_neg_x(r)));
        }
        else if( r[0] % 2 == 0 && r[1] % 2 == 1) {
            spin[site_idx].set_NN(0, site_index(shift_pos_x(r)));
            spin[site_idx].set_NN(1, site_index(shift_neg_y(r)));
            spin[site_idx].set_NN(2, site_index(shift_neg_x(r)));
        }
        else if( r[0] % 2 == 1 && r[1] % 2 == 0) {
            spin[site_idx].set_NN(0, site_index(shift_neg_x(r)));
            spin[site_idx].set_NN(2, site_index(shift_pos_x(r)));
            spin[site_idx].set_NN(3, site_index(shift_neg_y(r)));
        }
        else if( r[0] % 2 == 1 && r[1] % 2 == 1) {
            spin[site_idx].set_NN(0, site_index(shift_neg_x(r)));
            spin[site_idx].set_NN(2, site_index(shift_pos_x(r)));
            spin[site_idx].set_NN(3, site_index(shift_pos_y(r)));
        }
    }
}

int IsingSystem_Honey::site_index(const std::vector<int>& lattice_coordinate) const {
    int x = lattice_coordinate[0];
    int y = lattice_coordinate[1];
    int row_length = system_size[1];
    return y * row_length + x;
}

std::vector<int> IsingSystem_Honey::lattice_coordinate(int site_index) const {
    int row_length = system_size[1];
    int y = site_index / row_length;
    int x = site_index % row_length;
    return {x, y};
}

std::vector<int> IsingSystem_Honey::shift_pos_x(const std::vector<int>& r_spec) const {
    std::vector<int> r(r_spec);
    r[0] = (r[0] + 1) % system_size[0];
    return r;
}

std::vector<int> IsingSystem_Honey::shift_pos_y(const std::vector<int>& r_spec) const {
    std::vector<int> r(r_spec);
    r[1] = (r[1] + 1) % system_size[1];
    return r;
}

std::vector<int> IsingSystem_Honey::shift_neg_x(const std::vector<int>& r_spec) const {
    std::vector<int> r(r_spec);
    r[0] = (r[0] - 1 + system_size[0]) % system_size[0];
    return r;
}

std::vector<int> IsingSystem_Honey::shift_neg_y(const std::vector<int>& r_spec) const {
    std::vector<int> r(r_spec);
    r[1] = (r[1] - 1 + system_size[1]) % system_size[1];
    return r;
}

int IsingSystem_Honey::NN(const int site_idx, const int bond_idx) const{
    return spin[site_idx]._NN(bond_idx);
}

double IsingSystem_Honey::eval_energy() const{
    double H = 0;
    for (const auto& s : spin) {
        for (const auto& s_NN : s._NN())
        {
            H += IsingSystem_Honey::J * s._sz() * spin[s_NN]._sz();
        }
    }
    H /= 2;
    return H;
}

double IsingSystem_Honey::weight_unnormalized(double beta) const {
    double H = eval_energy(); // 使用已有的eval_energy函数计算能量
    double weight = exp(-beta * (H - J * 2 * n_spins)); // 计算Boltzmann权重
    return weight;
}

void IsingSystem_Honey::exactly_evaluate_given() {
    int Mz = eval_Mz(); // 当前状态的总磁化
    double H = eval_energy();
    for (size_t beta_idx = 0; beta_idx < beta.size(); ++beta_idx) {
        //std::cout<<"imfine"<<std::endl;
        double weight = exp(-beta[beta_idx] * (H - J * 2 * n_spins)); // Boltzmann权重
        // 假设这里的"Z"仅代表Boltzmann因子，因为我们考虑单个状态
        _exact_energy_Z_results[beta_idx] += weight;
        //std::cout<<"imfine"<<std::endl;
        _exact_energy_q_results[beta_idx] += weight * H;
        //std::cout<<"imfine"<<std::endl;
        _exact_energy_q_sq_results[beta_idx] += weight * H * H;
        //std::cout<<"imfine"<<std::endl;
        _exact_magz_Z_results[beta_idx] += weight; 
        //std::cout<<"imfine"<<std::endl;
        _exact_magz_q_sq_results[beta_idx] += Mz * Mz * weight;
        //std::cout<<"imfine"<<std::endl;
    }
}

void IsingSystem_Honey::normalize_direct() {
    for (std::size_t i = 0; i < beta.size(); ++i) {
        // 确保配分函数的值不为零
        if (_exact_energy_Z_results[i] != 0) {
            // 归一化能量期望值
            _exact_energy_q_results[i] /= _exact_energy_Z_results[i];
            // 归一化能量平方的期望值
            _exact_energy_q_sq_results[i] /= _exact_energy_Z_results[i];
            // 磁化的Z值理论上应该与能量的Z值相同，所以这里不再单独归一化
            // 归一化磁化平方的期望值
            _exact_magz_q_sq_results[i] /= _exact_magz_Z_results[i];
        }
    }
}

void IsingSystem_Honey::exactly_evaluate(const long long& rep_state) {
    set_state_by_code(rep_state);
    exactly_evaluate_given();
}

void IsingSystem_Honey::exactly_evaluate(const std::vector<bool>& state) {
    set_state(state);
    exactly_evaluate_given();
}

void IsingSystem_Honey::exact() {
    long long rep_state = 0;
    _exact_energy_Z_results.resize(beta.size(), 0);
    _exact_energy_q_results.resize(beta.size(), 0);
    _exact_energy_q_sq_results.resize(beta.size(), 0);
    _exact_magz_Z_results.resize(beta.size(), 0);
    _exact_magz_q_sq_results.resize(beta.size(), 0);
    while (rep_state <= maxrep_state) {
        exactly_evaluate(rep_state++);
    }
    normalize_direct();
}

void IsingSystem_Honey::print_exact() const {
    std::cout << "Exact calculations results:\n";
    for (size_t i = 0; i < beta.size(); ++i) {
        std::cout << "Beta = " << beta[i] << ":\n";
        std::cout << "  Z (Partition Function): " << _exact_energy_Z_results[i] << "\n";
        std::cout << "  <E> (Energy Expectation): " << _exact_energy_q_results[i] << "\n";
        std::cout << "  <E^2> (Energy Squared Expectation): " << _exact_energy_q_sq_results[i] << "\n";
        std::cout << "  Z (Mag Partition Function): " << _exact_magz_Z_results[i] << "\n";
        std::cout << "  <Mz^2> (Magnetization Squared Expectation): " << _exact_magz_q_sq_results[i] << "\n";
    }
}
