#include <iostream>
#include <random>
#include <ctime>
#include "UnitStats.h"
#include "Unit.h"
#include "ArmyManager.h"

using namespace std;

void EndScreen(ArmyManager* attacker, ArmyManager* defender)
{
	cout << endl << endl;
	cout << attacker->unitStats.name << " left: " << attacker->number << endl;
	cout << defender->unitStats.name << " left: " << defender->number << endl;

	return;
}

int main()
{
	mt19937 randomGenerator(time(nullptr));

	UnitStats humanStats = { "human", 100, 12, 23, 0.0, 1.0, 80 };
	UnitStats orcStats = { "orc", 120, 16, 30, 0.0, 1.0, 70 };
	UnitStats monsterStats = { "monster", 300, 73, 127, 0.0, 1.0, 60 };

	auto monster = Unit(monsterStats, randomGenerator);
	auto human = Unit(humanStats, randomGenerator);
	auto orc = Unit(orcStats, randomGenerator);

	auto isDead = false;


	auto noAttackers = 7;
	auto noDefenders = 1;

	auto monsters = new ArmyManager(&monster, monsterStats, noDefenders);
	auto humans = new ArmyManager(&human, humanStats, noAttackers);
	auto orcs = new ArmyManager(&orc, orcStats, noDefenders);
	auto attacker = humans;
	auto defender = monsters;

	while(!isDead)
	{
		attacker->Attack(defender);
		if (defender->unit->HP == 0 && defender->number == 0)
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

	EndScreen(attacker, defender);

	system("PAUSE");
	return 0;
}