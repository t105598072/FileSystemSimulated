#ifndef FIND_VISITOR_H
#define FIND_VISITOR_H

#include <string>

#include "node_visitor.h"

using namespace std;

class File;
class Folder;

class FindVisitor : public NodeVisitor
{
public:
  FindVisitor(string nodeName);

  void visitFolder(Folder * Folder);
  void visitFile(File * file);

  string findResult();//return relative path which are found by name.

private:
  string _relativePath;
  string _currentNodeName;
  string _currentNodePath;
  string _nodeName;	
};

#endif