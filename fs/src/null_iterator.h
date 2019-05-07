#ifndef NULL_ITERATOR_H
#define NULL_ITERATOR_H

#include <vector>
#include <map>
#include "node_iterator.h"
#include "node.h"

using namespace std;
class NullIterator:public NodeIterator
{
public:
  NullIterator(Node * n): _node(n)
  {
  }

  void first()
  {
    //_it = _node->_children.begin();
  }
  Node* currentItem()
  {
    /*
    if (isDone())
    {
      throw string("no current item");
    }
    */
    return _node;
  }
  void next() 
  {
    /*
    if (isDone())
    {
      throw std::string("moving past the end");
    }
    */
    //_node->next(); 
  }
  bool isDone()
  {
    return true;
  }
private:
  Node * _node;
  map<string, Node *>::iterator _it;
};

#endif