#include <iostream>
#include <vector>
#include "IsingSystem.hpp"

int main(int argc, char** argv) {
//	IsingSpin spin;
//	std::cout << "Spin state (initial) : "<< spin._sz() << std::endl;
//	
//	spin.flip();
//	std::cout << "Spin state (initial) : "<< spin._sz() << std::endl;
//	
//	spin.flip();
//	std::cout << "Spin state (initial) : "<< spin._sz() << std::endl;
//	
//	const int n_spin = 10; //number of spins
//	std::vector<IsingSpin> spin_array(n_spin);
//	
//	const double J = -1;
//	double energy = 0;
//	for (int i = 1; i <= n_spin; i++) {
//		energy += spin_array[(i-1) % n_spin]._sz() * spin_array[i % n_spin]._sz();
//	}
//	energy *= J;
//	std::cout << "Energy = " << energy << std::endl;
//	
	#include "IsingSystem.hpp"

    // 创建一个有10个自旋的伊辛模型系统
    const int n_spins = 10;
    IsingSystem system(n_spins);

    // 配置#7
    long long state_code = 7;
    system.set_state_by_code(state_code);
    double mz_7 = system.eval_mz();
    double energy_1D_7 = system.eval_energy_1D();
    std::cout << "Configuration #" << state_code << ":" << std::endl;
    std::cout << "Total Magnetization (M): " << mz_7 << std::endl;
    std::cout << "Total Energy (E): " << energy_1D_7 << std::endl << std::endl;

    // 配置#77
    state_code = 77;
    system.set_state_by_code(state_code);
    double mz_77 = system.eval_mz();
    double energy_1D_77 = system.eval_energy_1D();
    std::cout << "Configuration #" << state_code << ":" << std::endl;
    std::cout << "Total Magnetization (M): " << mz_77 << std::endl;
    std::cout << "Total Energy (E): " << energy_1D_77 << std::endl << std::endl;

    // 配置#777
    state_code = 777;
    system.set_state_by_code(state_code);
    double mz_777 = system.eval_mz();
    double energy_1D_777 = system.eval_energy_1D();
    std::cout << "Configuration #" << state_code << ":" << std::endl;
    std::cout << "Total Magnetization (M): " << mz_777 << std::endl;
    std::cout << "Total Energy (E): " << energy_1D_777 << std::endl << std::endl;
	return 0;
}