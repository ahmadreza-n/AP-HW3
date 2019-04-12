#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include <vector>

class CHuman
{
private:
  std::string firstName;
  std::string lastName;
  int hairColor;
  int eyeColor;
  int age;
  bool gender; //false for male and true for female
  int numberOfChildren;
  CHuman *mother;
  CHuman *father;
  CHuman *spouse;
  CHuman **children;

public:
  CHuman() = default;
  CHuman(std::string firstName, std::string lastName,
         int hairColor, int eyeColor, int age,
         bool gender, int numberOfChildren);
  ~CHuman();
  CHuman(const CHuman &);

  std::string getFirstName() const;
  std::string getLastName() const;
  bool getGender() const;
  int getHairColor() const;
  int getEyeColor() const;
  int getAge() const;
  CHuman *getSpouse() const;

  void setFirstName(const std::string);
  void setSpouse(CHuman *);
  void setChild(CHuman *);

  bool operator<(const CHuman &) const;
  bool operator==(const CHuman &) const;
  CHuman *operator+(CHuman &);
  CHuman &operator=(const CHuman &);
  void operator++(int);
  bool isChildOf(const CHuman *) const;
  bool isFatherOf(const CHuman *) const;
  bool isMotherOf(const CHuman *) const;
  void printChildren();
  void sortChildren();
};

#endif //HUMAN_H