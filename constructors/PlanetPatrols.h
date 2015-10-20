#pragma once
#include <iostream>
#include "PlayerStats.h"
#include "OrbitLocs.h"
#include "Enemies.h"
using namespace std;

enum Planets { EARTH, MOON, VENUS, MARS, THE_REEF };

bool playerAlive = true;
bool moveForward = false;
//Earth Patrol -> Consists mainly of Fallen, and a very small amount of hive with the scale of 1 for stats
void Fight(Enemy a, Planets planet )
{
	bool enemyAlive = true;
	bool happenedOnce = false;
	char answer;
	string PlanetName;
	//chain of if's will set the enemy stats on scale with what planet the fight is taking place on
	if (planet == EARTH)    { a.SetScaleForPlanet(1);    PlanetName = "Earth"; }
	if (planet == MOON)     { a.SetScaleForPlanet(1.5);  PlanetName = "Moon";  }
	if (planet == VENUS)    { a.SetScaleForPlanet(2);    PlanetName = "Venus"; }
	if (planet == MARS)     { a.SetScaleForPlanet(2.5);  PlanetName = "Mars";  }
	if (planet == THE_REEF) { a.SetScaleForPlanet(3);    PlanetName = "Reef";  }
	while (enemyAlive == true && playerAlive == true)
	{
		system("CLS");
		a.setEnemyHealth(a.getEnemyHealth() - Guardian.getDamage());//Enemy health = current health - player damage
		if (happenedOnce == false)
		{
			cout << "You attack the" << a.getCombinedName() << " with an " << Guardian.getWeaponName() << " for " << Guardian.getDamage() << " Damage" << endl;
		}
		else if (happenedOnce == true)
		{
			cout << "you attack the" << a.getCombinedName() << " again for" << Guardian.getDamage() << " damage, his health is now " << a.getEnemyHealth() << endl;
		}
		//when the enemy has died
		if (a.getEnemyHealth() <= 0)
		{
			enemyAlive = false;
			bool moveOn = false;
			cout << "You have killed the " << a.getCombinedName() << " and have received " << a.getEnemyXP() << " XP" << endl;
			system("pause");
			UpdateExperience(a.getEnemyXP());
			cout << endl;
			PrintPlayerLevelStats();
			while (moveOn == false)
			{
				cout << "Would you like to fight another or go back to the " << PlanetName << " Menu" << endl;
				cout << "stay and [F]ight or go back to the [P]lanet menu?" << endl;
				cin >> answer;

				if (answer == 'f')
				{
					moveOn = true;
				}
				else if (answer == 'p') {
					moveForward = true;
					moveOn = true;
				}
				else
				{
					cout << "Sorry but that is an invalid answer, please try again..." << endl << endl;
				}
			}

		}else//if you do not kill the enemy on the first strike, it will attack you
		{
			Guardian.setHealth(Guardian.getHealth() - a.getEnemyDamage());
			cout << "the " << a.getCombinedName() << " has attacked you for " << a.getEnemyDamage() << " Damage" << endl;
			system("pause");

		}
		if (Guardian.getHealth() <= 0) { playerAlive = false; cout << "YOU HAVE FAILED GUARDIAN" << endl; cout << " The " << a.getEnemyName() << " laughs demonicly" << endl; }
		happenedOnce = true;
	}
	enemyAlive = true;
}
void EarthPatrol()
{
	char answer;
	
	cout << "Are you sure that you want to patrol earth" << endl;
	cout << "[Y]es or [N]o\?" << endl;
	cin >> answer;
	if (answer == 'n'){moveForward = true;} // Let the player have the change to leave before fighting

	while (moveForward == false && playerAlive == true)
	{
		Enemy enemy(FALLEN);
		Fight(enemy, EARTH);
	}
}

void MoonPatrol()
{
	char answer;

	cout << "Are you sure that you want to patrol the Moon" << endl;
	cout << "[Y]es or [N]o\?" << endl;
	cin >> answer;
	if (answer == 'n') { moveForward = true; } // Let the player have the change to leave before fighting

	while (moveForward == false && playerAlive == true)
	{
		Enemy enemy(HIVE);
		Fight(enemy, MOON);
	}
}

void VenusPatrol()
{
	char answer;

	cout << "Are you sure that you want to patrol Venus" << endl;
	cout << "[Y]es or [N]o\?" << endl;
	cin >> answer;
	if (answer == 'n') { moveForward = true; } // Let the player have the change to leave before fighting

	while (moveForward == false && playerAlive == true)
	{
		Enemy enemy(VEX);
		Fight(enemy, VENUS);
	}
}

void MarsPatrol()
{
	char answer;

	cout << "Are you sure that you want to patrol Mars" << endl;
	cout << "[Y]es or [N]o\?" << endl;
	cin >> answer;
	if (answer == 'n') { moveForward = true; } // Let the player have the change to leave before fighting

	while (moveForward == false && playerAlive == true)
	{
		Enemy enemy(CABAL);
		Fight(enemy, MARS);
	}
}


