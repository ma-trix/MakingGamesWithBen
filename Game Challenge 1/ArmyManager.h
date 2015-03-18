#pragma once
#include "Unit.h"

class ArmyManager
{
public:
	ArmyManager(Unit unit, int number);
	void Attack(ArmyManager army_manager);
	int number;
	Unit unit;
};