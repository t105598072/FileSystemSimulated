#ifndef NODE_VISITOR_H
#define NODE_VISITOR_H

#include <string>

using namespace std;

class File;
class Folder;
class Link;

class NodeVisitor
{
public:
    virtual void visitFolder(Folder * folder) = 0;
    virtual void visitFile(File * file) = 0;
    virtual void visitLink(Link * link) = 0;
    virtual string findResult()
    {
		throw string("findResult: not applicable");
    }
    virtual int getContentSize()
    {
    	throw string("getContentSize: not applicable");
    }
};

#endif