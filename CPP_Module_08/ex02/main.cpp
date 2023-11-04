#include "MutantStack.hpp"

int main()
{
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);

  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
  std::cout << "Now with list!!!" << std::endl;
  std::list<int> lst;
  lst.push(5);
  lst.push(17);
  std::cout << lst.top() << std::endl;
  lst.pop();
  std::cout << lst.size() << std::endl;
  lst.push(3);
  lst.push(5);
  lst.push(737);

  //[...]
  lst.push(0);
  MutantStack<int>::iterator lst_it = lst.begin();
  MutantStack<int>::iterator lst_ite = lst.end();
  ++it;
  --it;
  while (lst_it != lst_ite)
  {
    std::cout << *lst_it << std::endl;
    ++lst_it;
  }
  std::list<int> l(lst);
  return 0;
}
