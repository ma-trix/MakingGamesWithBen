#pragma once
#include "Unit.h"

class ArmyManager
{
public:
	ArmyManager(Unit* unit, UnitStats unitStats, int number);
	void Attack(ArmyManager* army_manager);
	Unit* selectDefender();
	void AttackedBy(Unit* assailant);
	int number;
	Unit* unit;
	UnitStats unitStats;
	~ArmyManager();
};