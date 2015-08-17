#include <filesystem>
#include "UnitStats.h"
#include "Unit.h"
#include <iostream>

float Unit::Attack(Unit* opponent)
{
	uniform_real_distribution<float> hitRoll(hitLow, hitHigh);
	cout << "A: " << name << " | D: " << opponent->name << endl;
	if (hitRoll(randomGenerator) * 100 <= hitPercentage)
	{
		uniform_real_distribution<float> dmgRoll(dmgLow, dmgHigh);
		auto dmg = dmgRoll(randomGenerator);
		opponent->dealDmg(dmg);
		return dmg;
	}
	cout << "MISS !!" << endl;
	return 0;
}

float Unit::dealDmg(float dmg)
{
	cout << dmg << " damage dealt." << endl;
	if (HP > dmg)
	{
		HP = HP - dmg;
		cout << HP << " HP left for " << name << endl;
		return HP;
	}
	cout << name << " died." << endl;
	HP = 0;
	
	return HP;
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