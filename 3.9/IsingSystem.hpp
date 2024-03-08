#ifndef IsingSystem_hpp
#define IsingSystem_hpp

#include <iostream>
#include <cassert>
#include <cmath>

class IsingSpin
{
	private:
		int sz; /*It's the spin direction of the object +/-1 */

	public:
		IsingSpin() {sz = 1;};
		~IsingSpin() {};
		
		int _sz() const {return sz;};
		void set_up() {sz = 1;};
		void set_dw() {sz = -1;};
		void set_sz(int sz_spec){
			assert(sz_spec == 1 or sz_spec == -1);
			sz = sz_spec;
		};
		void flip()
		{
			sz *= -1;
		};
};


class IsingSystem {
private:
    const double J;
    const int n_spins;
    const long long maxrep_state;
    std::vector<IsingSpin> spin;

public:
    IsingSystem(const int n_spins_spec) : J(-1.0), n_spins(n_spins_spec),
    maxrep_state(static_cast<long long>(std::pow(2, n_spins)) - 1) {
        spin.resize(n_spins);
    };
    virtual ~IsingSystem() {};

    double _J() const { return J; };
    int _n_spins() const { return n_spins; };
    long long _maxrep_state() const { return maxrep_state; };

    int _sz(const int site_idx) const { return spin[site_idx]._sz(); };
    void set_up_spin(const int site_idx) { spin[site_idx].set_up(); };
    void set_dw_spin(const int site_idx) { spin[site_idx].set_dw(); };
    void set_spin(const int site_idx, int s_spec)
        { spin[site_idx].set_sz(s_spec); };
    void flip_spin(const int site_idx) { spin[site_idx].flip(); };

    void set_state_by_code(long long rep_state) {
		assert(rep_state >= 0 && rep_state <= maxrep_state);
    	for (int i = 0; i < n_spins; ++i)
		{
        	// Determine the spin state based on the i-th bit of rep_state
        	int spin_state = (rep_state & (1LL << i)) ? 1 : -1;
        	spin[i].set_sz(spin_state);
    	}
	};
    double eval_mz() const {
		double mz = 0;
    	for (int i = 0; i < n_spins; ++i)
		{
        	mz += spin[i]._sz();
    	}
    	return mz;
	};
    double eval_energy_1D() const {
    	double energy = 0;
    	for (int i = 0; i < n_spins; ++i) {
        	// Periodic Boundary Conditions (PBC)
        	int next_spin = (i + 1) % n_spins;
        	energy += J * spin[i]._sz() * spin[next_spin]._sz();
    	}
    	return energy;
	};
};

#endif