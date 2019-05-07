#ifndef LINK_H
#define LINK_H
#include "node.h"

class Link : public Node
{
public:
  Link(const char * path, Node * node = nullptr) : Node(path)
  {
    if (!S_ISLNK(getSt().st_mode)) 
    {
      printf("Not current Link path in %s\n", path);
      throw string("Not current Link path");
    }

    this->addLink(node);
  }

  void accept(NodeVisitor * nv)
  {
    nv->visitLink(this);
  }

  void addLink(Node * node)
  {
    _source = node;
  }

  Node * getSource() {
    return _source;
  }

private:
  Node * _source;
};

#endif
