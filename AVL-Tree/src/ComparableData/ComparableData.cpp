#include "ComparableData.h"

ComparableData::ComparableData() : m_Id(++m_LastElementId) {}

bool ComparableData::Compare(const ComparableData& secondElement)
{
	return m_Id < secondElement.m_Id;
}
