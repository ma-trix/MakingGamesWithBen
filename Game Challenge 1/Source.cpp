#include <iostream>
#include <random>
#include <ctime>
#include "UnitStats.h"
#include "Unit.h"
#include "ArmyManager.h"

using namespace std;

int main()
{
	mt19937 randomGenerator(time(nullptr));

	UnitStats humanStats = { "human", 100, 12, 23, 0.0, 1.0, 80 };
	UnitStats orcStats = { "orc", 120, 16, 30, 0.0, 1.0, 70 };
	UnitStats monsterStats = { "monster", 2000, 73, 127, 0.0, 1.0, 60 };

	auto monster = Unit(monsterStats, randomGenerator);
	auto human = Unit(humanStats, randomGenerator);
	auto orc = Unit(orcStats, randomGenerator);

	auto isDead = false;

	
	int noAttackers = 1;
	int noDefenders = 1;

	ArmyManager* humans = new ArmyManager(&human, noAttackers);
	ArmyManager* orcs = new ArmyManager(&orc, noDefenders);
	auto attacker = humans;
	auto defender = orcs;

	while(!isDead)
	{
		attacker->Attack(defender);
		if (defender->unit->HP == 0)
		{
			isDead = true;
		}
		else 
		{
			auto tmp = attacker;
			attacker = defender;
			defender = tmp;
		}
	}

	system("PAUSE");
	return 0;
}