#include <iostream>
#include <string>

using namespace std;

const int numItems = 6;
const string shopItemNames[numItems] = { "Boots", "Swords", "Helmets", "Kittens", "Poleaxes", "Leggings" };

void printInventory (const int playerInventory[numItems]);
void printShop();
bool buyItems(int playerInventory[numItems]);

int main()
{
	bool isDone = false;
	int playerInventory[numItems] = {0, 0, 0, 1, 0, 0};

	cout << "*** Welcome to the item shop ***\n";

	while (!isDone) {
		printShop();

		printInventory(playerInventory);

		isDone = buyItems(playerInventory);
		cout << "\n\n\n";
	}

	cout << "Thanks for buying!";

	system("PAUSE");
	return 0;
}

void printInventory(const int playerInventory[numItems])
{
	for (int i = 0; i < numItems; i++)
	{
		if (playerInventory[i] > 0)
		{
			cout << playerInventory[i] << " x " << shopItemNames[i] << endl;
		}
	}
	cout << endl;
}

void printShop()
{
	cout << "Shop Inventory: \n";
	for (int i = 0; i < numItems; i++)
	{
		cout << i+1 << ". " << shopItemNames[i] << endl;
	}

	cout << "**************\n\n";
}

bool buyItems(int playerInventory[numItems])
{
	int input;
	cout << "What would you like to buy? Enter -1 to quit. Enter (" << 1 << "-" << numItems << "):";
	cin >> input;

	if(input == -1)
	{
		return true;
	}
	if(input < 0 || input > numItems)
	{
		cout << "That was a bad input!";
		return false;
	}

	playerInventory[input - 1]++;
	return false;
}