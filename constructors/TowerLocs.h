#pragma once
#include <iostream>
#include "LocationFunInit.h"
#include "PlayerStats.h"
#include "Factions.h"
//using namespace std;
void BountyTracker();
/*
				*TOWER LOCATIONS FILE*
*/

enum CabalBounties {NOT_AVALIBLE, KILL_100_CABAL};
enum FallenBounties {NA, KILL_100_FALLEN};

void CabalMissions(int Cabal_Bounty_Type)
{
	switch (Cabal_Bounty_Type) {
	case KILL_100_CABAL: Guardian.setPlayObj("Kill_100_Cabal"); break;
	}
}
void FallenMissions(int Fallen_Bounty_Type)
{
	switch (Fallen_Bounty_Type) {
	case KILL_100_FALLEN:Guardian.setPlayObj("Kill_100_Fallen"); break;
	}
}

void BountyText(char bountyType)//random texts for different missions
{
	int RNG = rand() % 2 + 1; // random number to be inputed for CabalMissions(HERE)
	switch (bountyType) {
	case 'S': cout << " Defeat 10 Majors / Ultras" << endl; //break;

	case 'P':
		switch (RNG) {
		case 1: cout << " Kill 100 cabal"; CabalMissions(KILL_100_CABAL); break;
		case 2: cout << "Kill 100 Fallen"; FallenMissions(KILL_100_FALLEN); break;
		}
		

	}

}
void BulletPoint(char bountyType) // used in the bountyTracker to show what type of bounty it is 
{
	cout << "/\\" << endl;
	cout << " " << bountyType << endl;
	cout << "\\/" << endl;
	BountyText(bountyType);
}


void DrawTower()
{
cout << "      |"                  << endl;
cout <<"      |(), "              << endl;
cout <<"      |/"                 << endl;
cout <<"  ____|_________________" << endl;
cout <<"  \\___\\____\\__|__/__/__/" << "		where would you like to go?" << endl;
cout <<"   \\___\\____\\_|_/__/__/"  << endl;
cout <<"    \\_________|______/"   << endl;
cout <<"       \\      |    |"     << "	[1] Postmaster" << endl;
cout <<"        \\     |    |"     << "	[2] Cryptarch " << endl;
cout <<"         \\    |    |"     << "	[3] Gunsmith  " << endl;
cout <<"          |   |    |"     <<  "	[4] Bounty Tracker" << endl;
cout <<"          |   |    |"     <<  "	[5] Shipwright" << endl;
cout <<"          |   |    |"     <<  "	[6] Guardian Factions" << endl;
cout <<"          |   |    |"     <<  "	[7] Go to Orbit" << endl;
cout << "          |   |   /" << "     [8] Guardian Stats" << endl;
cout << "          |   |  /"       << endl;
cout << "          |___|_/"        << endl;
}

void Tower()
{
	bool leave = false;
	enum TowerLocs { HAHAHANOOB, POSTMASTER, CRYPTARCH, GUNSMITH,BOUNTY,  SHIPWRIGHT,GUARDIAN_FACTIONS, ORBIT, PLAYER_STATS };
	int answer = 0;
	PlaySound(NULL, 0, 0);
	
	string Welcome = "[Welcome to the Tower]";
	
	while (leave == false)
	{
		system("CLS");
		cout << "\t\t\t\t";
		//RandomText(2);
		SlowPrint(Welcome, 20);
		cout << endl;
		DrawTower();
		//cout << "\t\t\t\t";
		
	/*	cout << "[1] Postmaster" << endl;
		cout << "[2] Cryptarch " << endl;
		cout << "[3] Gunsmith  " << endl;
		cout << "[4] Bounty Tracker" << endl;
		cout << "[5] Shipwright" << endl << endl;
		cout << "[6] Go to Orbit" << endl;*/
		cout << "...The rest of the Tower is under construction sorry for the inconvenience..." << endl;
		cout << "\n\n\n";
		cin >> answer;

		switch (answer){
		case POSTMASTER:PostMaster(); break;
		case CRYPTARCH :break;
		case GUNSMITH  :break;
		case SHIPWRIGHT:break;
		case BOUNTY    :BountyTracker(); break;
		case GUARDIAN_FACTIONS: DeadOrbit(false,Guardian.getGlimmer());
		case ORBIT     :leave = true; break;
		case PLAYER_STATS:  PrintPlayerLevelStats();
		default        :Tower();break;
		}


		system("pause");
	}
	Orbit();

}

void PostMaster()
{
	bool HasNewMessages = false;
	char answer;
	int newMessages = 1;

	if (newMessages > 0){HasNewMessages = true;}
	
	cout << "\t\t\t\t Welcome to the Postmaster" << endl;// << " !" << endl;
	if (HasNewMessages == false){
		cout << "you currently do not have any new messages please come back later" << endl;
		system("pause");
	}
	else
{
		cout << "\t\t\t";
		cout << "you currently have " << newMessages << " new messages Guardian" << endl;

		if (newMessages == 1){
			cout << "Would you like to read it?" << endl;
			cout << "[Y]es or [N]o..." << endl;
			cin >> answer;
		}
		else
		{
			cout << "Would you like to read them?" << endl;
			cout << "[Y]es or [N]o..." << endl;
			cin >> answer;
		}

		switch (answer){
		case 'y': break;
		case 'n': cout << "Have a good day Guardian" << endl;
			      system("pause");break;
		}
	}
	system("pause");
	//LOC = TOWER;
}

void Cryptarch()
{
	cout << "What can I decrypt for you today Guardian" << endl;
	//if player has engrams  then decrypting == true
	//else (go to items to buy)


	//if decrypting == true  then (after engram had been given an RNG value, 
	//decrypt and output the type of item given and color assosiated with it)
}

void Gunsmith(int glimmer) //use the glimmer input to show what the guardian can buy
{
	
}

void BountyTracker()
{
	cout << "<Track you're Bounties>" << endl;
	
	for (int i = 11; i > 0; --i)
	{
		int RNG = rand() % 2 + 1;
		switch (RNG) {
		case 1: BulletPoint('P'); break;
		case 2: BulletPoint('S'); break;
		}
	}
	
}

