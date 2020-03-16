#pragma once
#include "ComparableData.h"

class Person : public ComparableData
{
	const char* Name, Surname;
public:
	bool Compare(const ComparableData& secondElement) override;
};

