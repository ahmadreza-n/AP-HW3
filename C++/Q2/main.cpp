#include <iostream>
#include "vector.h"
#include <utility>

using namespace std::rel_ops;
int main() {
    CVector temp{};
    for(size_t i = 0; i < 10; i++)
    {
        temp.push_back(i);
        std::cout << "i = " << i << ", size = " << temp.size << ", capacity = " << temp.capacity << std::endl;
    }
    std::cout << "=======\n";
    for(size_t i = 0; i < 10; i++)
    {
        temp.pop_back();
        std::cout << "i = " << i << ", size = " << temp.size << ", capacity = " << temp.capacity << std::endl;
    }
    return 0;
}