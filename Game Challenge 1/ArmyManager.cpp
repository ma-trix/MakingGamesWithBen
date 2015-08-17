#include "ArmyManager.h"
#include "Unit.h"
#include <iostream>

ArmyManager::ArmyManager(Unit* unit, UnitStats unitStats, int number) :
	number(number),
	unitStats(unitStats),
	unit(unit)
{
}

void ArmyManager::Attack(ArmyManager* opposingArmy)
{
	opposingArmy->AttackedBy(unit);
}

void ArmyManager::AttackedBy(Unit* assailant)
{
	auto defender = selectDefender();
	assailant->Attack(defender);
	if (defender->HP == 0)
	{
		number--;
	}
}

Unit* ArmyManager::selectDefender()
{
	if(unit->HP == 0 && number > 0)
	{
		unit = new Unit(unitStats, unit->randomGenerator);
		
		cout << endl << number << " " << unit->name << " left" << endl << endl;
	}
		
	return unit;
}

ArmyManager::~ArmyManager()
{
}