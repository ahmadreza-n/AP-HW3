#include "maxHeap.h"
#include <iostream>
#include <cmath>

CMaxHeap::CMaxHeap()
{
    maxHeap.push_back(0);
    n = 0;
}

CMaxHeap::~CMaxHeap()
{
}

void CMaxHeap::buildMaxHeap()
{
    for (int i{n / 2}; i > 0; i--)
        maxHeapify(i);
}

void CMaxHeap::maxHeapify(int i)
{
    int j{2 * i};
    int temp{maxHeap[i]};

    while (j <= n)
    {

        if (j < n && (maxHeap[j + 1] > maxHeap[j]))
            j++;

        if (temp > maxHeap[j])
            break;

        else if (temp <= maxHeap[j])
        {
            maxHeap[j / 2] = maxHeap[j];
            j *= 2;
        }
    }

    maxHeap[j / 2] = temp;
}

void CMaxHeap::add(int key)
{
    maxHeap.push_back(key);
    n++;
    buildMaxHeap();
}

int CMaxHeap::deleteMax()
{
    int temp{maxHeap[1]};
    maxHeap[1] = maxHeap[n];
    maxHeap.erase(maxHeap.begin() + n);
    n--;
    buildMaxHeap();
    return temp;
}

int CMaxHeap::getMaxKey()
{
    return maxHeap[1];
}

int CMaxHeap::getHeight()
{
    return static_cast<int>(log2(n)) + 1;
}

int CMaxHeap::getParent(int i)
{
    return maxHeap[i / 2];
}

int CMaxHeap::getRightChild(int i)
{
    return maxHeap[(2 * i) + 1];
}

int CMaxHeap::getLeftChild(int i)
{
    return maxHeap[2 * i];
}

void CMaxHeap::print()
{
    int counter{1};
    for (size_t i = 0; i < static_cast<size_t>(log2(n)) + 1; i++)
    {
        for (size_t j = 0; j < pow(2, i) && (counter < n + 1); j++)
            std::cout << maxHeap[counter++] << ", ";

        std::cout << std::endl;
    }
}

void CMaxHeap::heapSort()
{
    std::vector<int> temp;
    int temp2{};
    while(n > 0) {
        temp2 = this->deleteMax();
        temp.push_back(temp2);
        std::cout << temp2 << ", ";
    }

    for(size_t i = 0; i < temp.size(); i++)
        this->add(temp[i]);
    
    buildMaxHeap();
    
    std::cout << std::endl;
}
