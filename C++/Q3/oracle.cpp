#include "oracle.h"

COracle::COracle(std::string name_) : name{name_}
{
}

bool COracle::marry(CHuman *human1, CHuman *human2)
{
    if (human1->getSpouse() == nullptr && human2->getSpouse() == nullptr &&
        human1->getAge() >= 18 && human2->getAge() >= 18)
    {
        human1->setSpouse(human2);
        human2->setSpouse(human1);
        return true;
    }
    return false;
}

void COracle::setChild(CHuman *child, CHuman *mother, CHuman *father)
{
    father->setChild(child);
    mother->setChild(child);
}
