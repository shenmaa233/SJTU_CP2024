#include "matplotlibcpp.h"
#include <vector>

namespace plt = matplotlibcpp;

int main() {
    // Prepare data
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {1, 4, 9, 16, 25};

    // 使用named_plot来添加带标签的数据序列
    plt::named_plot("line", x, y, "r--"); // 现在使用named_plot代替plot，并指定标签

    // Set x-axis to interval [0,6] and y-axis to interval [0,30]
    plt::xlim(0, 6);
    plt::ylim(0, 30);

    // Add graph title and axes labels
    plt::title("Sample figure");
    plt::xlabel("x axis");
    plt::ylabel("y axis");

    // Enable legend.
    plt::legend(); // 这会显示标签

    // Save the image (file format is determined by the extension)
    plt::save("./test_plot.png");

    // Display plot in a window
    plt::show();

    return 0;
}
