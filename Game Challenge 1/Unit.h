#pragma once
#include "UnitStats.h"
#include <random>

using namespace std;

class Unit
{
public:
	string name;
	float HP;
	int dmgLow;
	int dmgHigh;
	float hitLow;
	float hitHigh;
	int hitPercentage;
	mt19937 randomGenerator;
	float Attack(Unit* opponent);
	float dealDmg(float dmg);
	Unit(UnitStats stats, mt19937 randomG);
};