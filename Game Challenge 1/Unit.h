#pragma once

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
	float attackFor();
	float dealDmg(float dmg);
	Unit(UnitStats stats, mt19937 randomG);
};