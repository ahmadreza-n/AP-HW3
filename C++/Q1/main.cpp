#include"maxHeap.h"

int main() {
    CMaxHeap temp{};
    for(size_t i = 0; i < 10; i++)
    {
        temp.add(i);
    }
    temp.deleteMax();
    temp.print();
    temp.heapSort();
    temp.deleteMax();
    temp.print();
    return 0;
}