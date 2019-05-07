#ifndef FOLDER_H
#define FOLDER_H

#include <vector>
#include <string>
#include <map>
#include "node.h"
#include "info_content_visitor.h"
#include "find_visitor.h"
#include "node_iterator.h"
#include "null_iterator.h"

class Folder : public Node{
public:
  class FolderIterator : public NodeIterator
  {
  public:
    FolderIterator(Folder * f): _folder(f)
    {

    }

    void first()
    {
      _it = _folder->_children.begin();
    }
    Node* currentItem()
    {
      if (isDone())
      {
        throw std::string("no current item");
      }
      return _it->second;
    }
    void next()
    {
      if (isDone())
      {
        throw std::string("moving past the end");
      }
      _it++;
    }
    bool isDone()
    {
      return _it == _folder->_children.end();
    }
  private:
    Folder * _folder;
    map<string, Node *>::iterator _it;
  };

  Folder(const char* path):Node(path)
  {
    if (!S_ISDIR(getSt().st_mode)) 
    {
      throw string("Not current DIR path");
    }

  }

  void add(Node *node)
  {
    _children[node->name()] = node;
    //_children.push_back(node);
  }

  int numberOfChildren() const
  {
    return _children.size();
    //return _children.size();
  }
  /*
  void acceptIVC(InfoContentVisitor * icv)
  {
    icv->visitFolder(this);
  }
  */
  
  void accept(NodeVisitor * fv)
  {
    fv->visitFolder(this);
  }

  NodeIterator * createIterator()
  {
    return new FolderIterator(this);
  }

  string find(std::string nodeName) const 
  {
    string currentNodeName = name();
    string currentNodePath = "/"+name();

    if(numberOfChildren() == 0)
      return "";
    else
    {
      string result = ".";
      vector<Node *> v;
      saveTreeNode(nodeName, v);
      for (auto const& node: v) 
      {
        string p = node->getPath();
        if (node->name() == getTopNode()) {
          result += "/n";
        }   
        size_t pos = p.find(currentNodePath);
        size_t cnnSize = currentNodeName.size(); 
        result += p.substr(pos + cnnSize + 1);
        result += node->name();
      }
      return result;
    }
  }

  void saveTreeNode(string nodeName, vector<Node *>& vNode) const {
  for (auto const& childern : _children)
  {
    Node * childrenNode = childern.second;
    if (childrenNode->name() == nodeName) 
    {
      vNode.push_back(childrenNode);
    }
    childrenNode->saveTreeNode(nodeName, vNode);
  }

  /*
    for (int i=0;i<_children.size();i++) 
    {
      Node * childrenNode = _children[i];
      if (childrenNode->name() == nodeName) {

        vNode.push_back(childrenNode);
      }
      childrenNode->saveTreeNode(nodeName, vNode);
    }
  */
  }
private:
  std::map<std::string, Node *> _children;
  int _key;
};

#endif