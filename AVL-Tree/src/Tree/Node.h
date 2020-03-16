#pragma once
#include "fwd.h"
#include "../ComparableData/ComparableData.h"

class Node
{
public:
	Node(ComparableData* dataPtr) : m_Data(dataPtr), m_Left(nullptr), m_Right(nullptr), m_BalanceFactor(0), m_Height(0) {}

	ComparableDataUPtr m_Data;

	NodePtr m_Left, m_Right;
	int m_BalanceFactor, m_Height;
};

