#pragma once
#include "fwd.h"
#include "Node.h"

class AVLTree
{
private:
	NodePtr m_Root;

	bool Contains(NodePtr node, ComparableData& data);
	NodePtr Insert(NodePtr node, ComparableData& data);
	void Update(NodePtr node);
	NodePtr Rebalance(NodePtr node);
	NodePtr LeftLeftCase(NodePtr node);
	NodePtr LeftRightCase(NodePtr node);
	NodePtr RightLeftCase(NodePtr node);
	NodePtr RightRightCase(NodePtr node);
	NodePtr LeftRotation(NodePtr node);
	NodePtr RightRotation(NodePtr node);

public:
	bool Contains(ComparableData& data);
	bool Insert(ComparableData& data);
};

