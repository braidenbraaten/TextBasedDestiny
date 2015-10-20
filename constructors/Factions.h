#pragma once
#include <iostream>
#include "TowerLocs.h"
#include "PlayerStats.h"
#include <string>
using namespace std;
void DeadOrbitStore(int guardianGlimmer)
{
	bool leave = false;
	int weaponCost[5] = {200, 300, 450, 500, 600};
	//response bools in order
	bool responses[] = { false,false, false }; // Weapons, Armor, Supplies
	string storeWeapons[5] = { " Crypt Dweller SR1"," Unwilling Soul-09"," Hide and Seek-42"," Deviant Gravity-A"," Final Rest II" };
	int saidOnce = 0;
	char answer;

	UpdateExperience(80);
	cout << "Welcome " << Guardian.getName() << " what would you like to look at?" << endl;
	while (leave == false)
	{
		if (saidOnce >= 1) { cout << "Sorry, that was an incorrect response," << endl << "Please respond correctly..." << endl; } 
			
		cout << "[W]eapons" << endl;
		cout << "[A]rmor" << endl;
		cout << "[S]upplies" << endl;
		cin >> answer;
		++saidOnce;
		switch (answer)
		{
			case 'w':responses[0] = true; break;
			case 'a':responses[1] = true; break;
			case 's':responses[2] = true; break;
			default: break;
		}
		if (responses[0] == true || responses[1] == true || responses[2] == true){leave = true;}
	}
	leave = false;
	saidOnce = 0;
	if (responses[0] == true)
	{
		char answer;
		string WShop = "Welcome to the Weapons Shop";SlowPrint(WShop, 5);
		if (Guardian.getPlayerLevel() < 5)
		{
			cout << "Alright newby , we gotta get you something to defend yourself with, what weapon do you want?" << endl;
			switch (Guardian.getPlayerLevel())
			{
				case 5:	cout << "[5]" << storeWeapons[4] << endl;
				case 4:	cout << "[4]" << storeWeapons[3] << endl;
				case 3:	cout << "[3]" << storeWeapons[2] << endl;
				case 2:	cout << "[2]" << storeWeapons[1] << endl;
				case 1: cout << "[1]" << storeWeapons[0] << endl;
				
				
				
			}
			cin >> answer;
			cout << "are you sure that you want to buy the";
			switch (answer)
			{
				
			case '1':cout << storeWeapons[0] << " for " << weaponCost[0] << " Glimmer" << endl; break;
			case '2':cout << storeWeapons[1] << " for " << weaponCost[1] << " Glimmer" << endl; break;
			case '3':cout << storeWeapons[2] << " for " << weaponCost[2] << " Glimmer" << endl; break;
			case '4':cout << storeWeapons[3] << " for " << weaponCost[3] << " Glimmer" << endl; break;
			case '5':cout << storeWeapons[4] << " for " << weaponCost[4] << " Glimmer" << endl; break;
			}
			cout << "[Y]es or [N]o?" << endl;
			cin >> answer;
			switch (answer)
			{
				case 'y': Guardian.setGlimmer(Guardian.getGlimmer() - weaponCost[0]);
				case 'n':break;
			}
			system("pause");
		}
	}


}

void FactionStore(int whichFaction)
{
	
	switch (whichFaction)
	{
	case DEAD_ORBIT: DeadOrbitStore(Guardian.getGlimmer()); break;
	case NEW_MONARCHY: break;
	case FUTURE_WAR_CULT: break;
	}
	
}


void DeadOrbit(bool isCurrentFaction, int playerGlimmer)
{
	char answer;

	bool leave     = false;//leave that area
	bool selection = false;//go to the shop
	bool join      = false;//Join the Faction

	if (isCurrentFaction == true){cout << "Welcome back DeadOrbit Guardian, what can i do for you today?" << endl;}
	while (leave == false)
	{
		cout << "Hello Guardian, would you like to see our selection or Join DeadOrbit?" << endl;
		cout << "Selection [S]" << endl;
		cout << "Join [J]"      << endl;
		cin >> answer;
		switch (answer)
		{
		case 's': selection = true; leave = true; break;
		case 'j': join      = true; leave = true; break;
		default: cout << "Sorry but the answer you have provided is incorrect, please try again" << endl;

		}
	}
	leave = false;
	if (selection == true)
	{
		FactionStore(Guardian.getFaction());
	}


}

void NewMonarchy()
{

}

void FutureWarCult()
{
	
}