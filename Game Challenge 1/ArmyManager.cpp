#include "ArmyManager.h"
#include "Unit.h"

ArmyManager::ArmyManager(Unit* unit, int number) :
	unit(unit),
	number(number)
{
}

void ArmyManager::Attack(ArmyManager* opposingArmy)
{
	opposingArmy->AttackedBy(unit);
}

void ArmyManager::AttackedBy(Unit* assailant)
{
	Unit* defender = selectDefender();
	assailant->Attack(defender);
}

Unit* ArmyManager::selectDefender()
{
	return unit;
}

ArmyManager::~ArmyManager()
{
}