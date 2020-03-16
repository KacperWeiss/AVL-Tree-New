#pragma once

class ComparableData
{
private:
	static int m_LastElementId;

public:
	int m_Id;

	ComparableData();
	virtual ~ComparableData() = default;

	virtual bool Compare(const ComparableData &secondElement);

};

