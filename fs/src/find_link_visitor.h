#ifndef FIND_LINK_VISITOR_H
#define FIND_LINK_VISITOR_H

#include <vector>

#include "node_visitor.h"

using namespace std;

class Node;
class File;
class Folder;

class FindLinkVisitor : public NodeVisitor
{
public:
    FindLinkVisitor();
    void visitFolder(Folder * folder);
    void visitFile(File * file);
    void visitLink(Link * link);
    std::vector<Node*>  getLinks();//return the Link objects.
private:
	vector<Node*> _linkObj;
};


#endif