#pragma once
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;


ofstream playerStats;

void DataInStream(float data, string defineData)
{
	
	playerStats << data << " " << defineData << endl;
	
}

void DataInStream(int data, string defineData)
{	
	playerStats << data << " " << defineData << "\n";
}

void StringInStream(string data, string defineData)
{
	playerStats << data << " " << defineData << "\n";

}


enum Armor {BASIC, SILLY_SAUCE, CAPTAIN_DAMN_BERRIES, HARDCORE_PARCORE, MASTA_CHIEF_STATUS};
enum Weapons {HAND_CANNON, AUTO_RIFLE, SCOUT_RIFLE, SNIPER_RIFLE, ROCKET};
enum PlayerType {meh, HUNTER, WARLOCK, TITAN};
enum Faction {NAFACTION, DEAD_ORBIT, NEW_MONARCHY, FUTURE_WAR_CULT};

void SlowPrint(const std::string& str, int delay_time) {
	for (size_t i = 0; i != str.size(); ++i) {
		cout << str[i];
		Sleep(delay_time);
	}
}

//Show Player Experience

void PrintLevelInfo(int pLevel,  int pExperience){cout << "Guardian Level: " << pLevel << " Guardian Experience: " << pExperience << endl;}

void RandomText(int wordLength)
{
	int x = 0;
	char Alphabet[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	while (x < wordLength)
	{
		for (int i = 0; i < 27; ++i)
		{
			cout << Alphabet[i];
		}
		++x;
	}
}
class Player
{
private:
	int health = 20 * (level + 2);
	float damageScale;
	float damage = 2.1 * (level + 1);
	int experience = 0;
	int glimmer = 1500;
	//sets the amount of levels and experience required in each one
	int level = 1;


	//player type
	Weapons PlayerWeapon;
	string weaponName;

	Armor PlayerArmor;
	Faction playerFaction = DEAD_ORBIT;
	char name[20];
	char *PlayerName = name;




	string CurrentPlayerObjective = "Get your first mission";
	string ShipName = "Arcadia Class JumpShip";

public:
	int pType = 0;
	string beginText = "Please enter in your Guardian's Name";
	Player()
	{
		SlowPrint(beginText, 40);
		cout.end;
		cout << "\n";
		cin.getline(name, 20);

		//setting the amount of experience needed for each levl 


		cout << "ok " << name << " What type of guardian would you like to play?" << endl;
		cout << "[1]Hunter" << endl;
		cout << "[2]Warlock" << endl;
		cout << "[3]Titan" << endl;
		cin >> pType;	
		switch (pType)
		{
		case HUNTER: PlayerWeapon = SCOUT_RIFLE; PlayerArmor = BASIC;                 break;
		case WARLOCK: PlayerWeapon = AUTO_RIFLE;  PlayerArmor = SILLY_SAUCE;           break;
		case TITAN: PlayerWeapon = HAND_CANNON; PlayerArmor = CAPTAIN_DAMN_BERRIES;  break;
		}

		if (PlayerWeapon == HAND_CANNON) { weaponName = " Hand Cannon"; damageScale = 1.5; }
		if (PlayerWeapon == AUTO_RIFLE) { weaponName = " Auto Rifle";  damageScale = 2; }
		if (PlayerWeapon == SCOUT_RIFLE) { weaponName = " Scout Rifle"; damageScale = 2.5; }
		if (PlayerWeapon == SNIPER_RIFLE) { weaponName = " Sniper Rifle"; damageScale = 3; }
		if (PlayerWeapon == ROCKET) { weaponName = " Rocket Launcher"; damageScale = 4; }
		damage = damage * damageScale;

	}
	//player name
	string getName() { return PlayerName; }

	//player glimmer
	int getGlimmer() { return glimmer; }
	void setGlimmer(int amount) { glimmer = amount; }

	//player level
	int getPlayerLevel() { return level; }
	void setPlayerLevel(int newLevel) { level = newLevel; }

	//player experience
	int getPlayerExperience() { return experience; }
	void setExperience(int amtOfAddedXP) { experience += amtOfAddedXP; }

	//bounties / objectives
	void setPlayObj(string text) { CurrentPlayerObjective = text; }
	string getPlayObj() { return CurrentPlayerObjective; }

	//vehicle
	void setShip(string newShipName) { ShipName = newShipName; }
	string getShipName() { return ShipName; }

	//weapons
	void setWeapon(Weapons weaponOfChoice) { PlayerWeapon = weaponOfChoice; }
	int getWeapon() { return PlayerWeapon; }
	string getWeaponName() { return weaponName; }
	void setWeaponName(string newName) { weaponName = newName; }
	int getDamage() { return damage; }

	//health
	void setHealth(int hp) { health = hp; }
	int getHealth() { return health; }
	//player faction
	void setFaction(Faction factionOfChoice) { playerFaction = factionOfChoice; }
	 int getFaction() { return playerFaction; }

	

};
//initializing the player
Player Guardian;

void DrawLevelUp()
{
	system("CLS");
	cout << "                                       L E V E L  U P " << endl;
	cout << "                                       _____    _____ " << endl;
	cout << "                                       \\___/ __ \\___/ " << endl;
	cout << "                                       /___\\ \\/ /___\\ " << endl;
	cout << "                                           / /\\ \\     " << endl;
	cout << "                                          / /  \\ \\    " << endl;
	cout << "                                         /_/    \\_\\   " << endl;
	cout << "                                        L E V E L  " << Guardian.getPlayerLevel() << endl;
}

int RemainderXP(int playerLevel)
{
	int remainingXP = 0;
	if (playerLevel == 1) { remainingXP =  (100  - Guardian.getPlayerExperience()); }
	if (playerLevel == 2) { remainingXP =  (200  - Guardian.getPlayerExperience()); }
	if (playerLevel == 3) { remainingXP =  (300  - Guardian.getPlayerExperience()); }
	if (playerLevel == 4) { remainingXP =  (400  - Guardian.getPlayerExperience()); }
	if (playerLevel == 5) { remainingXP =  (500  - Guardian.getPlayerExperience()); }
	if (playerLevel == 6) { remainingXP =  (600  - Guardian.getPlayerExperience()); }
	if (playerLevel == 7) { remainingXP =  (700  - Guardian.getPlayerExperience()); }
	if (playerLevel == 8) { remainingXP =  (800  - Guardian.getPlayerExperience()); }
	if (playerLevel == 9) { remainingXP =  (900  - Guardian.getPlayerExperience()); }
	if (playerLevel == 10) { remainingXP = (1000 - Guardian.getPlayerExperience()); }
	return remainingXP;
}

void PrintPlayerLevelStats()
{
	//enum Weapons {LAUGHABLE, POKEABLE, OHABLE, HURTABLE, KILLABLE};
	

	system("CLS");
	cout << "                              *P L A Y E R  S T A T S*               " << endl << endl;
	cout << "guardian Level: " << Guardian.getPlayerLevel() << " Experience till next Lvl: "<< RemainderXP(Guardian.getPlayerLevel()) << endl;
	cout << "Current Weapon: " << Guardian.getWeaponName() << " Dealing " << Guardian.getDamage() << " Damage " << endl; // Weapon Damage:  << Guardian.getWeaponDamage() << endl;
	cout << "Health: " << Guardian.getHealth()  << endl;
	//cout << "Current Ship  :" << Guardian.getShipName() << endl;
	system("pause");
}

void UpdateExperience(int addedXP)
{
	bool levelUp = false;
	static int happenedOnce = 0;
	Guardian.setExperience(addedXP);
	if (Guardian.getPlayerExperience()  < 100 && happenedOnce == 0) { Guardian.setPlayerLevel(1); ++happenedOnce; levelUp = true; }                       //Lvl 1
	if (Guardian.getPlayerExperience() >= 100 && Guardian.getPlayerExperience() < 200  && happenedOnce == 1) { Guardian.setPlayerLevel(2) ; ++happenedOnce; levelUp = true;}//Lvl 2
	if (Guardian.getPlayerExperience() >= 200 && Guardian.getPlayerExperience() < 300  && happenedOnce == 2) { Guardian.setPlayerLevel(3) ; ++happenedOnce; levelUp = true;}//Lvl 3
	if (Guardian.getPlayerExperience() >= 300 && Guardian.getPlayerExperience() < 400  && happenedOnce == 3) { Guardian.setPlayerLevel(4) ; ++happenedOnce; levelUp = true;}//Lvl 4  
	if (Guardian.getPlayerExperience() >= 400 && Guardian.getPlayerExperience() < 500  && happenedOnce == 4) { Guardian.setPlayerLevel(5) ; ++happenedOnce; levelUp = true;}//Lvl 5
	if (Guardian.getPlayerExperience() >= 500 && Guardian.getPlayerExperience() < 600  && happenedOnce == 5) { Guardian.setPlayerLevel(6) ; ++happenedOnce; levelUp = true;}//Lvl 6
	if (Guardian.getPlayerExperience() >= 600 && Guardian.getPlayerExperience() < 700  && happenedOnce == 6) { Guardian.setPlayerLevel(7) ; ++happenedOnce; levelUp = true;}//Lvl 7
	if (Guardian.getPlayerExperience() >= 700 && Guardian.getPlayerExperience() < 800  && happenedOnce == 7) { Guardian.setPlayerLevel(8) ; ++happenedOnce; levelUp = true;}//Lvl 8  
	if (Guardian.getPlayerExperience() >= 800 && Guardian.getPlayerExperience() < 900  && happenedOnce == 8) { Guardian.setPlayerLevel(9) ; ++happenedOnce; levelUp = true;}//Lvl 9
	if (Guardian.getPlayerExperience() >= 900 && Guardian.getPlayerExperience() < 1000 && happenedOnce == 9) { Guardian.setPlayerLevel(10); ++happenedOnce; levelUp = true;}//Lvl 10
//	if (Guardian.getPlayerExperience() >= 1000 && Guardian.getPlayerExperience() < 1100 && happenedOnce == 10) { Guardian.setPlayerLevel(11); ++happenedOnce; }//Lvl 11



	if (levelUp == true) 
	{
		DrawLevelUp();
		system("pause");
		system("CLS");
	}

	levelUp = false;

}

void SaveStats()
{
	playerStats.open("playerInfo.txt");
	//Player Name
	StringInStream(Guardian.getName(), "<-Guardian Name");
	//Player Level
	DataInStream(Guardian.getPlayerLevel(), "Guardian Level");
	//Experience
	DataInStream(Guardian.getPlayerExperience(), "Guardian XP");
	//Glimmer
	DataInStream(Guardian.getGlimmer(), "Guardian Glimmer");
	//Health
	DataInStream(Guardian.getHealth(), "Player Health");
	//damage
	DataInStream(Guardian.getDamage(), "Player Damage");
	//weaponNumber
	DataInStream(Guardian.getWeapon(), "Player Weapon Number");
	//Weapon Name
	StringInStream(Guardian.getWeaponName(), "Player Weapon Name");
	//Ship Name
	StringInStream(Guardian.getShipName(), "Player Ship Name");
	playerStats.close();
}
