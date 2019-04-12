#include <iostream>
#include "oracle.h"
#include <iostream>
#include <utility>

using namespace std::rel_ops;
int main()
{

    CHuman *p1{new CHuman{"ALI", "BAHADORI", 4, 3, 25, false, 0}};
    CHuman *p2{new CHuman{"BAHAR", "SHAMS", 1, 2, 22, true, 0}};
    CHuman *p3{};

    COracle o1{"SHERVIN"};

    //married couple
    o1.marry(p1, p2);

    //creating new person
    p3 = *p1 + *p2;

    //setting the firstname of newborn
    if (p3->getGender())
        p3->setFirstName("MAHSHID");
    else
        p3->setFirstName("FARSHID");

    //increasing the age of newborn
    (*p3)++;
    CHuman *p4{new CHuman{"SHAHIN", "REZAEE", 0, 5, 58, 1, 1}};
    CHuman *p5{new CHuman{"FARHAD", "BAHADORI", 0, 6, 63, 0, 1}};

    o1.setChild(p1, p4, p5);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}