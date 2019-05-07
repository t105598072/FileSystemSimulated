#include "find_link_visitor.h"
#include "node.h"
#include "link.h"
#include "file.h"
#include "folder.h"


FindLinkVisitor::FindLinkVisitor()
{

}

void FindLinkVisitor::visitFolder(Folder * folder) 
{
  NodeIterator * it = folder->createIterator();
  for (it->first(); !it->isDone(); it->next())
  {
    it->currentItem()->accept(this);
  }
}

void FindLinkVisitor::visitFile(File * file) 
{

}

void FindLinkVisitor::visitLink(Link * link) 
{
  _linkObj.push_back(link);
}//return the Link objects.

vector<Node*> FindLinkVisitor::getLinks() 
{
  return _linkObj;
}
