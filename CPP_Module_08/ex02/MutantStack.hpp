
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <list>

/*https://youtu.be/F9eDv-YIOQ0?si=YEeBVnnbk4IqYuci*/

template<typename T, typename ContainerType = std::deque<T> >
class MutantStack:public std::stack<T, ContainerType>
{
  public:
    MutantStack(): MutantStack<T, ContainerType>::stack() {std::cout << "Constructor MutantStack\n";};
    MutantStack(const MutantStack<T, ContainerType>& other): MutantStack<T, ContainerType>::stack(other){
      std::cout << "Copy\n";
    };
    virtual ~MutantStack(){};

    MutantStack<T, ContainerType>& operator=(const MutantStack<T, ContainerType> &src)
    {
      std::cout << "Copy assignment\n";
      if (this != &src)
        this->MutantStack<T, ContainerType>::stack::operator=(src);
      return (*this);
    }

    typedef typename ContainerType::iterator iterator;
    typedef typename ContainerType::const_iterator const_iterator;
    typedef typename ContainerType::reverse_iterator reverse_iterator;
    typedef typename ContainerType::const_reverse_iterator const_reverse_iterator;

    /*std::vector<T>::iterator*/
    iterator begin()
    {
      return (this->c.begin());
    }

    const_iterator begin() const
    {
      return (this->c.begin());
    }

    reverse_iterator rbegin()
    {
      return (this->c.rbegin());
    }

    const_reverse_iterator rbegin() const
    {
      return (this->c.rbegin());
    }

    iterator end()
    {
      return (this->c.end());
    }

    const_iterator end() const
    {
      return (this->c.end());
    }

    reverse_iterator rend()
    {
      return (this->c.rend());
    }

    const_reverse_iterator rend() const
    {
      return (this->c.rend());
    }
};

#endif
