#ifndef FIND_NODE_BY_PATHNAME_VISITOR_H
#define FIND_NODE_BY_PATHNAME_VISITOR_H 
#include "node_visitor.h"
#include <vector>
#include <string>

using namespace std;

class Node;

class FindNodeByPathnameVisitor : public NodeVisitor {

public:
    FindNodeByPathnameVisitor(std::vector<string>* pathnames);
    void visitFolder(Folder * folder);
    void visitFile(File * file);
    void visitLink(Link * link);
    Node * getNode() const; //    return the Node object if the path indicate the node in the file system, and if not, return nullptr.

private:
	int _findCheckKey;
  	string _nodePathnames;
    vector<string> * _pathnames;
    Node * _result;
};

#endif
