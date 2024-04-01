#include "IsingSystem_Square.hpp"

IsingSystem_Square::IsingSystem_Square(const std::vector<int>& system_size_spec)
    : IsingSystem(system_size_spec[0] * system_size_spec[1]), system_size(system_size_spec) {
    setup_NN();
}

IsingSystem_Square::~IsingSystem_Square() {
    // Destructor - No dynamic allocation, so empty
}

void IsingSystem_Square::setup_NN() {
    for (int site_idx = 0; site_idx < n_spins; ++site_idx) {
        std::vector<int> r = lattice_coordinate(site_idx);
        spin[site_idx].set_NN(0, site_index(shift_pos_x(r)));
        spin[site_idx].set_NN(1, site_index(shift_pos_y(r)));
        spin[site_idx].set_NN(2, site_index(shift_neg_x(r)));
        spin[site_idx].set_NN(3, site_index(shift_neg_y(r)));
    }
}

int IsingSystem_Square::site_index(const std::vector<int>& lattice_coordinate) const {
    int x = lattice_coordinate[0];
    int y = lattice_coordinate[1];
    int row_length = system_size[1];
    return y * row_length + x;
}

std::vector<int> IsingSystem_Square::lattice_coordinate(int site_index) const {
    int row_length = system_size[1];
    int y = site_index / row_length;
    int x = site_index % row_length;
    return {x, y};
}

std::vector<int> IsingSystem_Square::shift_pos_x(const std::vector<int>& r_spec) const {
    std::vector<int> r(r_spec);
    r[0] = (r[0] + 1) % system_size[0];
    return r;
}

std::vector<int> IsingSystem_Square::shift_pos_y(const std::vector<int>& r_spec) const {
    std::vector<int> r(r_spec);
    r[1] = (r[1] + 1) % system_size[1];
    return r;
}

std::vector<int> IsingSystem_Square::shift_neg_x(const std::vector<int>& r_spec) const {
    std::vector<int> r(r_spec);
    r[0] = (r[0] - 1 + system_size[0]) % system_size[0];
    return r;
}

std::vector<int> IsingSystem_Square::shift_neg_y(const std::vector<int>& r_spec) const {
    std::vector<int> r(r_spec);
    r[1] = (r[1] - 1 + system_size[1]) % system_size[1];
    return r;
}

int IsingSystem_Square::NN(const int site_idx, const int bond_idx) const{
	return spin[site_idx]._NN(bond_idx);
}

double IsingSystem_Square::eval_energy() const{
	double H = 0;
	for (const auto& s : spin) {
		for (const auto& s_NN : spin._NN())
        {
        	H += IsingSystem_Square::J * s._sz() * s_NN._sz();
        }
    }
    H /= 2;
    return H;
}
