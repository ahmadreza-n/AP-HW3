#if !defined(VECTOR_H)
#define VECTOR_H

class CVector
{
  public:
    int size, capacity;

  private:
    int *arr;

  public:
    CVector();
    CVector(const CVector &vec);
    CVector(CVector &&vec);
    ~CVector();

    void push_back(const int &num);
    int pop_back();

    bool operator<(const CVector &) const;
    bool operator==(const CVector &) const;
};

#endif //VECTOR_H