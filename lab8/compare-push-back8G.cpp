#include <iostream>
using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

#include <cassert>

typedef double ElType;

class MinimalVec {
public:
  MinimalVec() : storeM(0), sizeM(0), capM(0) { }
  ~MinimalVec() { delete [ ] storeM; }

  const ElType& at(size_t i) const { return storeM[i]; }
  size_t size() const { return sizeM; }

  void push_back_A(const ElType& item);
  void push_back_B(const ElType& item);

private:
  // Declaring the copy constructor and copy assignment operator
  // private makes it impossible to copy objects of a class.  I'm
  // doing this because I don't want to put time into writing those
  // functions for this class, but do want to prevent weird results
  // caused by inadvertent memberwise copy.
  MinimalVec(const MinimalVec& src);
  MinimalVec& operator =(const MinimalVec rhs);
  
  ElType *storeM;
  size_t sizeM;
  size_t capM;
};

void MinimalVec::push_back_A(const ElType& item)
{
  if (sizeM == capM) {
    capM += 1;
    ElType *new_store = new ElType[capM];
    for (size_t i = 0; i < sizeM; i++) {
      new_store[i] = storeM[i];  // LINE A
    }
    delete [ ] storeM;
    storeM = new_store;
  }
  storeM[sizeM] = item;
  sizeM++;
}

void MinimalVec::push_back_B(const ElType& item)
{
  if (capM == 0) {
    capM = 1;
    storeM = new ElType[1];
  }
  else if (sizeM == capM) {
    capM *= 2;
    ElType *new_store = new ElType[capM];
    for (size_t i = 0; i < sizeM; i++) {
      new_store[i] = storeM[i];  // LINE B
    }
    delete [ ] storeM;
    storeM = new_store;
  }
  storeM[sizeM] = item;
  sizeM++;
}

const size_t push_count = 10;

int main() 
{
  MinimalVec mv1;
  for (size_t i = 0; i < push_count; i++)
    mv1.push_back_A(0.5 * i);

  // Quick checks that push_back_A did its job ...
  assert(mv1.size() == push_count);
  for (size_t i = 0; i < push_count; i++)
    assert(mv1.at(i) == 0.5 * i);

  MinimalVec mv2;
  for (size_t i = 0; i < push_count; i++)
    mv2.push_back_B(0.5 * i);

  // Quick checks of push_back_B ...
  assert(mv2.size() == push_count);
  for (size_t i = 0; i < push_count; i++)
    assert(mv2.at(i) == 0.5 * i);
 
  return 0;
}
