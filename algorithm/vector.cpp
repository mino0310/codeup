#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    for (int elem : vec) {
        std::cout << "원소 : " << elem << std::endl;
    }

    return 0;
}
