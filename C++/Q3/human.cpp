#include "human.h"
#include <iostream>

CHuman::CHuman(std::string first_name, std::string last_name,
               int hair_color, int eye_color, int age_,
               bool gender_, int number_of_children)
    : firstName{first_name},
      lastName{last_name},
      hairColor{hair_color},
      eyeColor{eye_color},
      age{age_}, gender{gender_},
      numberOfChildren{number_of_children}
{
    srand(time(NULL));
    children = new CHuman *[numberOfChildren] {};
}

CHuman::~CHuman()
{
    delete[] children;
}

CHuman::CHuman(const CHuman &human) : CHuman(human.firstName, human.lastName,
                                             human.hairColor, human.eyeColor,
                                             human.age, human.gender, human.numberOfChildren)
{
    children = new CHuman *[numberOfChildren];
    for (int i = 0; i < numberOfChildren; i++)
    {
        children[i] = human.children[i];
    }
}

std::string CHuman::getFirstName() const
{
    return firstName;
}

std::string CHuman::getLastName() const
{
    return lastName;
}

bool CHuman::getGender() const
{
    return gender;
}

int CHuman::getHairColor() const
{
    return hairColor;
}

int CHuman::getEyeColor() const
{
    return eyeColor;
}

int CHuman::getAge() const
{
    return age;
}

CHuman *CHuman::getSpouse() const
{
    return spouse;
}

void CHuman::setFirstName(const std::string first)
{
    firstName = first;
}

void CHuman::setSpouse(CHuman *human)
{
    spouse = human;
}

void CHuman::setChild(CHuman *human)
{
    int counter{};
    while (children[counter++])
        ;
    children[counter - 1] = human;
}

bool CHuman::operator<(const CHuman &human) const
{
    return age < human.age;
}

bool CHuman::operator==(const CHuman &human) const
{
    return age == human.age;
}

CHuman &CHuman::operator=(const CHuman &human)
{
    if (this == &human)
        return *this;

    firstName = human.firstName;
    lastName = human.lastName;
    hairColor = human.hairColor;
    eyeColor = human.eyeColor;
    age = human.age;
    gender = human.gender;
    numberOfChildren = human.numberOfChildren;

    delete[] children;
    children = new CHuman *[numberOfChildren];
    for (int i = 0; i < numberOfChildren; i++)
        children[i] = human.children[i];

    return *this;
}

CHuman *CHuman::operator+(CHuman &human)
{
    if (spouse == &human)
    {
        std::string last{(!gender) ? lastName : human.lastName};
        int hair{(rand() % 2) ? hairColor : human.hairColor};
        int eye{(rand() % 2) ? eyeColor : human.eyeColor};
        bool newGender{(rand() % 2) ? true : false};
        CHuman *child{new CHuman{"mamad", last, hair, eye, 0, newGender, 0}};

        numberOfChildren++;
        human.numberOfChildren++;
        CHuman **temp = new CHuman *[numberOfChildren];
        for (int i = 0; i < numberOfChildren - 1; i++)
        {
            temp[i] = children[i];
        }
        temp[numberOfChildren - 1] = child;
        delete[] children;
        children = temp;
        return child;
    }
    return nullptr;
}

void CHuman::operator++(int)
{
    age++;
}

bool CHuman::isChildOf(const CHuman *human) const
{
    for (int i = 0; i < (*human).numberOfChildren; i++)
        if (this == (*human).children[i])
            return true;

    return false;
}

bool CHuman::isFatherOf(const CHuman *human) const
{
    if (gender == true)
    {
        return false;
    }

    for (int i = 0; i < numberOfChildren; i++)
    {
        if (children[i] == human)
        {
            return true;
        }
    }
    return false;
}

bool CHuman::isMotherOf(const CHuman *human) const
{
    if (gender == false)
    {
        return false;
    }

    for (int i = 0; i < numberOfChildren; i++)
    {
        if (children[i] == human)
        {
            return true;
        }
    }
    return false;
}

void CHuman::printChildren()
{
    sortChildren();
    for (int i = 0; i < numberOfChildren; i++)
    {
        std::cout << children[i]->firstName << children[i]->getAge() << std::endl;
    }
}

void CHuman::sortChildren()
{
    if (numberOfChildren == 0)
        return;

    bool done{false};
    while (!done)
    {
        done = true;
        for (int i = 0; i < numberOfChildren - 1; i++)
            if (children[i]->age < children[i + 1]->age)
            {
                CHuman *temp{children[i]};
                children[i] = children[i + 1];
                children[i + 1] = temp;
                done = false;
            }
    }
}