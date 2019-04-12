#ifndef ORACLE_H
#define ORACLE_H

#include <string>
#include "human.h"

class COracle
{
private:
  std::string name;

public:
  COracle() = default;
  COracle(std::string name_);
  bool marry(CHuman *, CHuman *);
  void setChild(CHuman *, CHuman *, CHuman *);
};

#endif //ORACLE_H