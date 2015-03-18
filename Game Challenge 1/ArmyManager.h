#pragma once
#include "Unit.h"

class ArmyManager
{
public:
	ArmyManager(Unit* unit, int number);
	void Attack(ArmyManager* army_manager);
	Unit* selectDefender();
	void AttackedBy(Unit* assailant);
	int number;
	Unit* unit;
	~ArmyManager();
};