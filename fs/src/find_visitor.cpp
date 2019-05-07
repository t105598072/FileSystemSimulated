#include <iostream>
#include "find_visitor.h"
#include "file.h"
#include "folder.h"
#include "node_iterator.h"

FindVisitor::FindVisitor(string nodeName): _nodeName(nodeName)
{
}

void FindVisitor::visitFile(File * file)
{
  _currentNodeName = file->name();
  if (_nodeName == _currentNodeName)
    _relativePath = _nodeName;
  else
    _relativePath = "";
}

void FindVisitor::visitFolder(Folder * folder)
{
  if(folder->numberOfChildren() == 0)
  	_relativePath = "";
  else
  {
    _relativePath = "";

	vector<Node*> v;
	bool isNewLine = false;
	folder->saveTreeNode(_nodeName, v);
	string result = ".";

	_currentNodeName = folder->name();
	_currentNodePath = "/"+folder->name();

	for (auto const& node: v) 
	{
	  string p = node->getPath();
	  if (node->name() == folder->getTopNode()) 
	  {
	    isNewLine = true;
	  }

	  size_t pos = p.find(_currentNodePath);
	  size_t cnnSize = _currentNodeName.size(); 
	  result += p.substr(pos + cnnSize + 1);
	  result += node->name();
	}
	int numNodeName = folder->countSubstring(result , _nodeName);
	for(int i = 1 ; i < numNodeName ; i++)
	{
      size_t posEnd = folder->getStrPos(result, _nodeName,i);
	  size_t pos = result.find(_nodeName);
	  size_t cnnSize = _nodeName.size(); 
	  result = result.insert(posEnd + cnnSize,"\n.");
	}
	_relativePath = result;
  }
}

string FindVisitor::findResult() {
    return _relativePath;
}
