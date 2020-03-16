#pragma once
#include "fwd.h"
#include "../ComparableData/ComparableData.h"

class Node
{
public:
	ComparableData m_Data;

	NodeUPtr m_Left, m_Right;
	int m_BalanceFactor, m_Height;
};

