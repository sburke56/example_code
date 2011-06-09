#ifndef _HIDDENCLASS_HPP_
#define _HIDDENCLASS_HPP_

class Hiddenclass {
private:
  int hca;
  int hcb;
public:
  Hiddenclass(int a, int b);
  ~Hiddenclass();
  int multiply() const;
  int divide() const;
  int add() const;
  int subtract() const;
};

#endif
