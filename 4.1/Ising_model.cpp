#include "IsingSystem_Square.hpp"
#include "matplotlibcpp.h"
#include <vector>
#include <cmath>
#include <string>

namespace plt = matplotlibcpp;

int main() {
    std::vector<double> temperature;
    for (double tmp = 0.05; tmp <= 4; tmp += 0.05) {
        temperature.push_back(tmp);
    }

    std::vector<std::vector<double>> magnetizationSquaredAllSizes;
    std::vector<std::vector<double>> heatCapacityAllSizes;
    std::vector<double> beta_values(temperature.size());
    beta_values.clear();
    for (double tmp : temperature) {
        //std::cout << 1.0 / beta << std::endl;
        double beta = 1.0 / tmp;
        beta_values.push_back(beta);
        //std::cout << tmp << std::endl;
    }

    // for (size_t i = 0; i < beta_values.size(); ++i) {
    //     std::cout << "Beta: " << beta_values[i] << ", Temperature: " << temperature[i] << std::endl;
    // }

    std::vector<std::string> colors = {"red", "green", "blue", "black"}; // 颜色，为不同尺寸使用不同颜色
    std::vector<std::string> labels; // 标签

    for (int n = 2; n <= 4; ++n) {
        std::vector<int> system_size = {n, n};
        IsingSystem_Square system(system_size, beta_values);

        system.exact(); // 执行所有beta值的精确计算
        system.print_exact();
        std::vector<double> magnetizationSquared;
        std::vector<double> heatCapacity;
        //std::vector<double> energyperspin;

        for (size_t i = 0; i < beta_values.size(); ++i) {
            double beta = beta_values[i];

            double M2 = system._exact_magz_q_sq(i) / double(system._n_spins()*system._n_spins());
            double E = system._exact_energy_q(i);
            double E2 = system._exact_energy_q_sq(i);
            double C = (E2 - E * E) * beta * beta / double(system._n_spins()); // 计算热容C

            magnetizationSquared.push_back(M2);
            heatCapacity.push_back(C);
            //energyperspin.push_back(E/system._n_spins());
        }

        magnetizationSquaredAllSizes.push_back(magnetizationSquared);
        heatCapacityAllSizes.push_back(heatCapacity);
        labels.push_back("n = " + std::to_string(n));
        // 假设是在n=2时的循环体内
        // std::cout << "Results for n = 2:" << std::endl;
        // for (size_t i = 0; i < beta_values.size(); ++i) {
        //     std::cout << "Beta: " << beta_values[i] << ", M^2: " << magnetizationSquared[i]
        //             << ", Heat Capacity: " << heatCapacity[i] << std::endl;
        // }
    }
    std::cout << "Temperature vector size: " << temperature.size() << std::endl;
    std::cout << "MagnetizationSquared vector size for n=2: " << magnetizationSquaredAllSizes[0].size() << std::endl;
    std::cout << "HeatCapacity vector size for n=2: " << heatCapacityAllSizes[0].size() << std::endl;
    
    // 绘制<M^2>关于T的图
    plt::figure_size(1200, 600); // 设置图像大小
    for (size_t i = 0; i < magnetizationSquaredAllSizes.size(); ++i) {
        plt::named_plot(labels[i], temperature, magnetizationSquaredAllSizes[i], colors[i]);
    }
    plt::xlabel("Temperature (T)");
    plt::ylabel("<M^2>");
    plt::legend();
    plt::save("./M2_vs_T.png"); // 保存图像
    plt::clf(); // 清除当前图形以绘制下一个

    // 绘制C关于T的图
    for (size_t i = 0; i < heatCapacityAllSizes.size(); ++i) {
        plt::named_plot(labels[i], temperature, heatCapacityAllSizes[i], colors[i]);
    }
    plt::xlabel("Temperature (T)");
    plt::ylabel("Heat Capacity (C)");
    plt::legend();
    plt::save("./C_vs_T.png"); // 保存图像

    return 0;
}
