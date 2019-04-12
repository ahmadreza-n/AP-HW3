#include"vector.h"
#include<cmath>
CVector::CVector() : size{}, capacity{1}, arr{new int[1]}
{
}


CVector::CVector(const CVector& vec) : size{vec.size}, capacity{vec.capacity} {
    delete[] arr;
    arr = new int[capacity];
    for(int i = 0; i < size; i++)
        arr[i] = vec.arr[i];
    
}

CVector::CVector(CVector&& vec) : size{vec.size}, capacity{vec.capacity} {
    delete[] arr;
    arr = vec.arr;
    vec.arr = nullptr;
    vec.size = 0;
    vec.capacity = 0;
}

CVector::~CVector()
{
    delete[] arr;
}

void CVector::push_back(const int& num) {
    if (capacity > size)
        arr[size++] = num;
    else
    {
        capacity *= 2;
        int* temp = new int[capacity];
        for(int i = 0; i < size; i++)
            temp[i] = arr[i];
        
        temp[size++] = num;
        delete[] arr;
        arr = temp;
        temp = nullptr;
    }
}

int CVector::pop_back() {
    if (size == 0) {
        return -1;
    }

    int num{arr[--size]};
    
    if (size <= (capacity / 2)) {
        capacity /= 2;
        int* temp = new int[capacity];
        for(int i = 0; i < size; i++)
            temp[i] = arr[i];
        
        delete[] arr;
        arr = temp;
        temp = nullptr;
    }
    return num;
}

bool CVector::operator<(const CVector& vec) const {
    return size < vec.size;
}

bool CVector::operator==(const CVector& vec) const {
    return size < vec.size;
}
