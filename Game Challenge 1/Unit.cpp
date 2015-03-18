#include <filesystem>
#include "UnitStats.h"
#include "Unit.h"

float Unit::attackFor()
{
	uniform_real_distribution<float> hitRoll(hitLow, hitHigh);

	if (hitRoll(randomGenerator) * 100 <= hitPercentage)
	{
		uniform_real_distribution<float> dmgRoll(dmgLow, dmgHigh);
		return dmgRoll(randomGenerator);
	}
	return 0;
}

float Unit::dealDmg(float dmg)
{
	return (HP<dmg ? 0 : HP -= dmg);
}

Unit::Unit(UnitStats stats, mt19937 randomG) : 
	name(stats.name),
	HP(stats.HP),
	dmgLow(stats.dmgLow),
	dmgHigh(stats.dmgHigh),
	hitLow(stats.hitLow),
	hitHigh(stats.hitHigh),
	hitPercentage(stats.hitPercentage),
	randomGenerator(randomG)
{
}