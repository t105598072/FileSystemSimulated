#ifndef NODE_H
#define NODE_H
#include <sys/stat.h>
#include <string>
#include <vector>
#include <algorithm>

#include "node_iterator.h"
#include "find_visitor.h"

using namespace std;
class InfoContentVisitor;
class FindVisitor;
class Node
{
public:
  Node(const char * path): _path(path)
  {
    if(lstat(_path, &_st)!=0)
    {
      throw string("No such file or directory.");
    }
    _parent = nullptr;
  }

  int size() const
  {
    return _st.st_size;
  }

  //virtual void acceptIVC(InfoContentVisitor * icv) = 0;
  virtual void accept(NodeVisitor * fv)
  {
    throw std::string("unable to accept");    
  }

  virtual void add(Node *node)
  {
    throw std::string("unable to add");
  }

  virtual int numberOfChildren() const
  {
    throw std::string("number of children: not applicable");
  }

  virtual NodeIterator* createIterator()
  {
    return nullptr;
  }

  virtual string find(string nodeName) const
  {
    throw string("find: not applicable");
  }

  virtual string name() const
  {
    string p = _path;
    string spcae = " ";
    string result = "";
    
    size_t found = p.find_last_of("/\\");

    result = p.substr(found + 1);

    return result;
  }

  virtual string getTopNode() const
  {
    string resutl = "";
    return resutl + name(); 
  }

  virtual string getPath() const
  {
    string p = _path;
    string spcae = " ";
    string result = "";

    size_t found = p.find_last_of("/\\");

    result = p.substr(0, found + 1);
    return result;
  }

  virtual void saveTreeNode(string nodeName, vector<Node*>& vNode) const
  {
  }

  virtual string getFirstPath() const
  {
    string p = _path;
    string slash = "/";
    string result = "";
    
    size_t foundStart = p.find(slash, 0);
    size_t foundEnd = p.find(slash, 2);

    result = p.substr(foundStart+1, foundEnd-1);

    return result;
  }

  virtual string getNodePath() const 
  {
    string p = _path;
    string slash = "/";
    string result = "";

    size_t foundEnd = p.find_last_of(slash);

    result = p.substr(0, foundEnd + 1);

    return result;
  }

  Node * getParent() const
  {
    return _parent;
  }
  void setParent (Node * p)
  {
    _parent = p;
  }


  void eraseSubStr(string & mainStr, const string & toErase)
  {
    // Search for the substring in string
    size_t pos = mainStr.find(toErase);
   
    if (pos != std::string::npos)
    {
      // If found then erase it from string
      mainStr.erase(pos, toErase.length());
    }
  }

  int countSubstring(const string& str, const string& sub)
  {
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != string::npos; offset = str.find(sub, offset + sub.length()))
    {
      ++count;
    }
    return count;
  }

  int getStrPos(const string& str, const string& sub, int num)
  {
    if (sub.length() == 0) return 0;
    int count = 0;
    int result = 0;
    for (size_t offset = str.find(sub); offset != string::npos; offset = str.find(sub, offset + sub.length()))
    {
      ++count;
      if(count==num)
        result = offset;
    }
    return result;
  }

  struct stat getSt()
  {
    return _st;
  }
  
private:
  const char * _path;
  struct stat _st;
  Node * _parent;
};

#endif
