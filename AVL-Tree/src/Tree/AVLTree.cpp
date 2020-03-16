#include "AVLTree.h"
#include "../ComparableData/ComparableData.h"

bool AVLTree::Contains(NodePtr node, ComparableData& data)
{
	if (node == nullptr)
	{
		return false;
	}

	if (node->m_Data->Compare(data))
	{
		return Contains(node->m_Right, data);
	}
	else
	{
		return Contains(node->m_Left, data);
	}

	return true;
}

NodePtr AVLTree::Insert(NodePtr node, ComparableData& data)
{
	if (node == nullptr)
	{
		return std::make_shared<Node>(data);
	}

	if (node->m_Data->Compare(data))
	{
		node->m_Right = Insert(node->m_Right, data);
	}
	else
	{
		node->m_Left = Insert(node->m_Left, data);
	}

	Update(node);
	return Rebalance(node);
}

void AVLTree::Update(NodePtr node)
{
	int leftNodeHeight = (node->m_Left == nullptr) ? 0 : node->m_Left->m_Height;
	int rightNodeHeight = (node->m_Right == nullptr) ? 0 : node->m_Right->m_Height;
	int MaxHeight = (leftNodeHeight > rightNodeHeight) ? leftNodeHeight : rightNodeHeight;

	node->m_Height = MaxHeight + 1;
	node->m_BalanceFactor = rightNodeHeight - leftNodeHeight;
}

NodePtr AVLTree::Rebalance(NodePtr node)
{
	if (node->m_BalanceFactor == -2)
	{
		if (node->m_Left->m_BalanceFactor <= 0)
		{
			return LeftLeftCase(node);
		}
		else
		{
			return LeftRightCase(node);
		}
	}
	else if(node->m_BalanceFactor == 2)
	{
		if (node->m_Right->m_BalanceFactor <= 0)
		{
			return RightLeftCase(node);
		}
		else
		{
			return RightRightCase(node);
		}
	}

	return node;
}

NodePtr AVLTree::LeftLeftCase(NodePtr node)
{
	return RightRotation(node);
}

NodePtr AVLTree::LeftRightCase(NodePtr node)
{
	node->m_Left = LeftRotation(node->m_Left);
	return LeftLeftCase(node);
}

NodePtr AVLTree::RightLeftCase(NodePtr node)
{
	node->m_Right = RightRotation(node->m_Right);
	return RightRightCase(node);
}

NodePtr AVLTree::RightRightCase(NodePtr node)
{
	return LeftRotation(node);
}

NodePtr AVLTree::LeftRotation(NodePtr node)
{
	NodePtr newParent = node->m_Right;
	node->m_Right = newParent->m_Left;
	newParent->m_Left = node;
	Update(node);
	Update(newParent);
	return newParent;
}

NodePtr AVLTree::RightRotation(NodePtr node)
{
	NodePtr newParent = node->m_Left;
	node->m_Left = newParent->m_Right;
	newParent->m_Right = node;
	Update(node);
	Update(newParent);
	return newParent;
}

bool AVLTree::Contains(ComparableData& data)
{
	return Contains(m_Root, data);
}

bool AVLTree::Insert(ComparableData& data)
{
	if (&data == nullptr)
	{
		return false;
	}
	else if (!Contains(m_Root, data))
	{
		m_Root = Insert(m_Root, data);
		return true;
	}

	return false;
}
