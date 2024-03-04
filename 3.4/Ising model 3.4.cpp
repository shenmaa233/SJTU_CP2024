#include <iostream>
#include <vector>
#include "IsingSystem.hpp"

int main(int argc, char** argv) {
	IsingSpin spin;
	std::cout << "Spin state (initial) : "<< spin._sz() << std::endl;
	
	spin.flip();
	std::cout << "Spin state (initial) : "<< spin._sz() << std::endl;
	
	spin.flip();
	std::cout << "Spin state (initial) : "<< spin._sz() << std::endl;
	
	const int n_spin = 10; //number of spins
	std::vector<IsingSpin> spin_array(n_spin);
	
	const double J = -1;
	double energy = 0;
	for (int i = 1; i <= n_spin; i++) {
		energy += spin_array[(i-1) % n_spin]._sz() * spin_array[i % n_spin]._sz();
	}
	energy *= J;
	std::cout << "Energy = " << energy << std::endl;
	
	return 0;
}