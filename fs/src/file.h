#ifndef FILE_H
#define FILE_H

#include <string>
#include <sys/stat.h>

#include "node.h"
#include "info_content_visitor.h"
#include "find_visitor.h"
#include "node_visitor.h"
#include "null_iterator.h"

using namespace std;
class File: public Node{
public:
  File(const char * path): Node(path)
  {
  	if (S_ISREG(getSt().st_mode)==0) 
  	{
      throw string("Not current File path");
    }

  	_path = path;
  	_key = 1;
  }
  /*
  void acceptIVC(InfoContentVisitor * icv)
  {
    icv->visitFile(this);
  }
  */
  
  void accept(NodeVisitor * fv)
  {
  	fv->visitFile(this);
  }
		
  string find(std::string nodeName) const 
  {
    if (nodeName == name())
      return nodeName;
    else
      return "";
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
    return name(); 
  }

  NodeIterator* createIterator() 
  {
    return new NullIterator(this);
  }
  
private:
  const char * _stPath;
  string _path;
  int _key;
};

#endif
