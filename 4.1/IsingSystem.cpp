#include "IsingSystem.hpp"
#include <cassert>

IsingSystem::IsingSystem(const int n_spins_spec) 
    : J(-1.0), n_spins(n_spins_spec), 
      maxrep_state(static_cast<long long>(std::pow(2, n_spins)) - 1) {
    spin.resize(n_spins);
}

IsingSystem::~IsingSystem() {
    // Destructor - Vector handles its own memory, so nothing specific to do here.
}

void IsingSystem::set_dim(int dim) {
    for (auto& each : spin) each.set_dim(dim);
}

std::vector<int> IsingSystem::_spin_position(const int site_idx) const {
    return spin[site_idx]._position();
}

std::vector<int> IsingSystem::_spin_NN(const int site_idx) const {
    return spin[site_idx]._NN();
}

int IsingSystem::_spin_NN(const int site_idx, const int bond_idx) const {
    return spin[site_idx]._NN(bond_idx);
}

double IsingSystem::_J() const {
    return J;
}

int IsingSystem::_n_spins() const {
    return n_spins;
}

long long IsingSystem::_maxrep_state() const {
    return maxrep_state;
}

int IsingSystem::_sz(const int site_idx) const {
    return spin[site_idx]._sz();
}

void IsingSystem::set_up_spin(const int site_idx) {
    spin[site_idx].set_up();
}

void IsingSystem::set_dw_spin(const int site_idx) {
    spin[site_idx].set_dw();
}

void IsingSystem::set_spin(const int site_idx, int s_spec) {
    spin[site_idx].set_sz(s_spec);
}

void IsingSystem::flip_spin(const int site_idx) {
    spin[site_idx].flip();
}

void IsingSystem::set_state_by_code(long long rep_state) {
    assert(rep_state >= 0 && rep_state <= maxrep_state);
    for (int i = 0; i < n_spins; ++i) {
        int spin_state = (rep_state & (1LL << i)) ? 1 : -1;
        spin[i].set_sz(spin_state);
    }
}

double IsingSystem::eval_Mz() const {
    double mz = 0;
    for (const auto& s : spin) {
        mz += s._sz();
    }
    return mz;
}

double IsingSystem::eval_energy_1D() const {
    double energy = 0;
    for (int i = 0; i < n_spins; ++i) {
        int next_spin = (i + 1) % n_spins;
        energy += J * spin[i]._sz() * spin[next_spin]._sz();
    }
    return energy;
    
}

void IsingSystem::set_state(const std::vector<bool> state) {
	for(int i = 0; i < n_spins; i++)
	{
		assert(state[i] == 1 or state[i] == 0);
		if(state[i] == 1)
			spin[i].set_up();
		if(state[i] == 0)
			spin[i].set_dw();
	}
}
