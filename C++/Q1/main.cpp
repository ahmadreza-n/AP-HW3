#include "maxHeap.h"
#include <iostream>
int main()
{
    std::cout << "\ntesting default constructor\n";
    CMaxHeap temp{};
    for (size_t i = 0; i < 10; i++)
    {
        temp.add(i);
    }
    temp.deleteMax();
    std::cout << "\nfirst print\n";
    temp.print();
    std::cout << "\nsorted\n";
    temp.heapSort();
    temp.deleteMax();
    std::cout << "\nsecond print\n";
    temp.print();
    std::cout << "\ntesting constructor by array\n";

    int arr[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    CMaxHeap temp2{arr, 10};
    temp2.deleteMax();
    std::cout << "\nfirst print\n";
    temp2.print();
    std::cout << "\nsorted\n";
    temp2.heapSort();
    temp2.deleteMax();
    std::cout << "\nsecond print\n";
    temp2.print();

    std::cout << "\ntesting constructor by vector\n";
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    CMaxHeap temp3{vec};
    temp3.deleteMax();
    std::cout << "\nfirst print\n";
    temp3.print();
    std::cout << "\nsorted\n";
    temp3.heapSort();
    temp3.deleteMax();
    std::cout << "\nsecond print\n";
    temp3.print();

    return 0;
}