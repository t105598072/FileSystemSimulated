#include "find_node_by_pathname_visitor.h"
#include "file.h"
#include "folder.h"
#include "link.h"

FindNodeByPathnameVisitor::FindNodeByPathnameVisitor(std::vector<string>* pathnames) : _pathnames(pathnames)
{
    _findCheckKey = 0;
    _result = nullptr;
    _nodePathnames = ".";
    for (auto const& nodeNameOnPath: * _pathnames) 
    {
        _nodePathnames += "/";
        _nodePathnames += nodeNameOnPath;
    }
}

void FindNodeByPathnameVisitor::visitFolder(Folder * folder) 
{
    string nodePath = folder->getNodePath()+folder->name();
    if (nodePath == _nodePathnames) {
        _result = folder;
    }

    NodeIterator* it = folder->createIterator();
    for (it->first(); !it->isDone(); it->next()) {
        it->currentItem()->accept(this);

        if (_findCheckKey > 0) {
            break;
        }
    }
}

void FindNodeByPathnameVisitor::visitFile(File * file) 
{
    string nodePath = file->getNodePath()+file->name();
    string nodeName = _pathnames->at(_pathnames->size()-1);
    if (nodePath == _nodePathnames) 
    {
        _result = file;
        _findCheckKey++; 
    }    

    if (nodeName == file->name() && _pathnames->size() == 1) 
    {
        _result = file;
        _findCheckKey++;
    }
}

void FindNodeByPathnameVisitor::visitLink(Link * link) 
{
    string nodePath = link->getNodePath()+link->name();
    string nodeName = _pathnames->at(_pathnames->size()-1);
    if (nodePath == _nodePathnames) 
    {
        _result = link;
        _findCheckKey++;
    }

    if (nodeName == link->name() && _pathnames->size() == 1) 
    {
        _result = link;
        _findCheckKey++; 
    }  
}

Node* FindNodeByPathnameVisitor::getNode() const 
{
    return _result;
}
