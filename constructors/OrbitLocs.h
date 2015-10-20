 #pragma once
#include <iostream>
#include "LocationFunInit.h"
#include "TowerLocs.h"
#include "PlayerStats.h"
#include "PlanetPatrols.h"
#include <ctime>
using namespace std;
/*
			*THIS IS THE ORBIT LOCATIONS FILE*
*/
void Orbit();

string inOrbitText = "You are Now in Orbit";

void DrawWarp(bool GoingUp)
{
	srand(time(NULL));
	//int RNG = rand() % 3;

	char Astroids[3] = "{}";
	char Stars = '.';
	int i = 500;
	int again = 2;
	bool atmosphereChange = false;
	while (again > 0)
	{
		while (i > 0)
		{

			if (GoingUp == true)//to orbit
			{
				if (i < 400 && i > 300) { system("color F0"); }
				if (i < 300 && i > 200) { system("color 70"); }
				if (i < 200 && i > 100) { system("color 80"); }
				if (i < 400 && i > 385 || i < 300 && i > 285 || i == 200 || i == 100) { atmosphereChange = true; }
				if (atmosphereChange == true)
				{
					cout << "_._______________________________________________________________________________________._" << endl;
					cout << "_.-----------------------------------------------------------------------------------------._" << endl;
					cout << "_.-----------------------------------------------------------------------------------------._" << endl;
					atmosphereChange = false;
				}
			}
			if (GoingUp == false)//to planet
			{
				if (i < 400 && i > 300) { system("color 80"); }
				if (i < 300 && i > 200) { system("color 70"); }
				if (i < 200 && i > 100) { system("color F0"); }
			}
			
			int ship = rand() % 5 + 1;
			switch (ship){
			case 1: cout << "\t\t\t\t\t\t |  *  ^ "    << endl;
				    cout << "\t\t\t\t\t\t | *   | ";    break;
			case 2: cout << "\t\t\t\t\t *     | "      << endl;
				    cout << "\t\t\t\t\t |   `  |";      break;
			case 3: cout << "\t\t\t\t\t\t\t       | "  << endl;
					cout << "\t\t\t\t\t\t\t |  ,   |";  break;
			case 4: cout << "\t\t\t\t |   '   "        << endl;
					cout << "\t\t\t\t |     | ";        break;
			case 5: cout << "\t |      | "           << endl;
					cout << "\t |      |";           break;
			}

			
			int RNG = rand() % 6 + 1;
			switch (RNG){
			case 1: cout << "\t\t\t\t\t\t\t\t\t";break;
			case 2: cout << "\t\t\t";		     break;
			case 3: cout << "\t";				 break;
			case 4: cout << "\t\t\t\t";			 break;
			case 5: cout << "\t\t\t\t\t\t\t\t";  break;
			case 6: cout << "\t\t\t\t\t\t";      break;
			}
			//cout << "\t\t\t\t\t\t\t\t";
			cout << Astroids;
			int x = rand() % 4 + 1;
			  
			switch (x){
			case 1:cout << " * "		  << Stars << endl;break;
			case 2:cout << ""			  << Stars << endl;break;
			case 3: cout << "           " << Stars << endl;break;
			case 4: cout << "  *   "	  << Stars << endl;break;
			}
			--i;
		}
		    --again;
	}
	system("color 07");
}

void DrawShip()
{
	cout << "	           \\         /      " << endl;
	cout << "   ______	   <--------->          ______" << endl;
	cout << "  / ___  \\         /  \\   /  \\         /  ___ \\  " << endl;
	cout << " / /o o\\  \\_  _____   |   |   _____  _/  /o o\\ \\ " << endl;
	cout << "< :[ O ]:   \\/_=_=_\\__\\___/__/_=_=_\\/   :[ O ]: >   " << endl;
	cout << " \\ \\o_o/    /    ___  _____  ___    \\    \\o_o/ /  " << endl;
	cout << "  \\	 __/    /  /{/_____\\}\\  \\    \\__      /" << endl;
	cout << "   \\____/  \\   /__ \\_       _/ __\\   /  \\____/    " << endl;
	cout << "     \\/     \\_/   \\  \\_____/  /   \\_/     \\/ " << endl;
	cout << "            / \\    \\_/=_=_=\\_/    / \\      " << endl;
	cout << "     	             \\_____/ " << endl;

}

void DrawInventory()
{
	string a = "                                                  ______________";
	string b = "                 ________________________________/ * O R B I T* \\ ";
	string c = "     ___________/ [ I N V E N T O R Y  M E N U ] \\_________ [O]_|  ";
	string d = "    /---[ W ]---\\______________/\\________________/---[A]---\\  / |   ";
	string e = "   /     *W E A P O N S*               *A R M O R*          \/   |    ";
	string f = "   |___________________________/\\___________________________|   |   ";
	string g = "   |\\    _________________    /\\/\\   ___________________   /|   |   ";
	string h = "   | \\  *M A T E R I A L S*  /    \\ *C O N S U M A B L E* / |   | ";
	string i = "   |  \\     ---[ M ]---     /\\    /\\      ---[ C ]---    /  |   | ";
	string j = "   |   \\___________________/  \\  /  \\___________________/   |  /  ";
	string k = "  /_\\__/ *S E T T I N G S* \\___\\/___/    *S H I P S*    \\__/_\\/ ";
	string l = "  \\_/  \\___________________-[S]--[B]-___________________/  \\_/ ";
	string m = "   |_______/               \\/  \\/  \\/               \\_______| ";
	SlowPrint(a, 2);
	cout << "\n";
	SlowPrint(b, 2);
	cout << "\n";
	SlowPrint(c, 2);
	cout << "\n";
	SlowPrint(d, 2);
	cout << "\n";
	SlowPrint(e, 2);
	cout << "\n";
	SlowPrint(f, 2);
	cout << "\n";
	SlowPrint(g, 2);
	cout << "\n";
	SlowPrint(h, 2);
	cout << "\n";
	SlowPrint(i, 2);
	cout << "\n";
	SlowPrint(j, 2);
	cout << "\n";
	SlowPrint(k, 2);
	cout << "\n";
	SlowPrint(l, 2);
	cout << "\n";
	SlowPrint(m, 2);
	cout << "\n";


}

void Inventory()
{
	char answer;
	bool Continue = false;

	while (Continue == false)
	{
		system("CLS");
		DrawInventory();
		cin >> answer;
		switch (answer)
		{
		case 'o': Orbit(); break;
		case 's': cout << "Lol, you thought that there was a settings tab in a text game" << endl; system("pause"); break;
		case 'w': break;//Weapons()
		case 'a': break;//Armor();
		case 'm': break;//Materials()
		case 'c': break;//Consumables()
		case 'b': break;//Ships()
		}
	}
}

void DrawSelectionMenu()
{
	cout << "\n" << endl;
	string a = "          (          [ S E L E C T I O N   M E N U  ]         )     ";
	string b = "           ___________________________________________________     ";
	string c = "          /           \\     _________________     /           \\    ";
	string d = "         /             \\   *I N V E N T O R Y*   /             \\   ";
	string e = "        /  ___________  \\     ---[  I  ]---     /  ___________  \\  ";
	string f = "       /  *S T R I K E*  \\_____________________/  *P A T R O L*  \\ ";
	string g = "       \\   ---[ S ]---   /      _________      \\  ---[  P  ]---  / ";
	string h = "        \\               /      *O R B I T*      \\               /  ";
	string i = "         \\             /      ---[  O  ]---      \\             /   ";
	string j = "          \\___________/___________________________\\___________/    ";
	string k = "           \\_________\\ \\     _______________     / /_________/     ";
	string l = "            \\ \\    / /  \\_  *B O U N T I E S*  _/  \\ \\    / /      ";
	string m = "             \\ \\__/ /     \\   ---[  B  ]---   /     \\ \\__/ /       ";
	string n = "              \\/  \\/       \\_________________/       \\/  \\/        ";
	SlowPrint(a, 1);
	cout << "\n";
	SlowPrint(b, 1);
	cout << "\n";
	SlowPrint(c, 1);
	cout << "\n";
	SlowPrint(d, 1);
	cout << "\n";
	SlowPrint(e, 1);
	cout << "\n";
	SlowPrint(f, 1);
	cout << "\n";
	SlowPrint(g, 1);
	cout << "\n";
	SlowPrint(h, 1);
	cout << "\n";
	SlowPrint(i, 1);
	cout << "\n";
	SlowPrint(j, 1);
	cout << "\n";
	SlowPrint(k, 1);
	cout << "\n";
	SlowPrint(l, 1);
	cout << "\n";
	SlowPrint(m, 1);
	cout << "\n";
	SlowPrint(n, 1);
	cout << "\n";

//cout << "          (          [ S E L E C T I O N   M E N U  ]         )     " << endl;
//cout << "           ___________________________________________________     " << endl;
//cout << "          /           \\     _________________     /           \\    " << endl;
//cout << "         /             \\   *I N V E N T O R Y*   /             \\   " << endl;
//cout << "        /  ___________  \\     ---[  I  ]---     /  ___________  \\  " << endl;
//cout << "       /  *S T R I K E*  \\_____________________/  *P A T R O L*  \\ " << endl;
//cout << "       \\   ---[ S ]---   /       _________     \\  ---[  P  ]---  / " << endl;
//cout << "        \\               /       *O R B I T*     \\               /  " << endl;
//cout << "         \\             /       ---[  O  ]---     \\             /   " << endl;
//cout << "          \\___________/___________________________\\___________/    " << endl;
//cout << "           \\_________\\ \\     _______________     / /_________/     " << endl;
//cout << "            \\ \\    / /  \\_  *B O U N T I E S*  _/  \\ \\    / /      " << endl;
//cout << "             \\ \\__/ /     \\   ---[  B  ]---   /     \\ \\__/ /       " << endl;
//cout << "              \\/  \\/       \\_________________/       \\/  \\/        " << endl;


}

void PlanetOptions(int Planet)
{

	switch (Planet)
	{
	case 1: 
		cout << "[P]atrol the Cosmodrome" << endl;
		cout << "[W]ill of Crota Strike" << endl;
		cout << "[D]evil's Lair Strike" << endl;
		cout << "[F]allen S.A.B.E.R. Strike" << endl;
		break;



	}
}

void Orbit()
{
	bool moveOn = false;
	char answer = 'q';
	DrawWarp(true);
	system("CLS");
	SlowPrint(inOrbitText, 40);
	cout << "\n\n\n";
	system("pause");
	while (moveOn == false)
	{

		DrawShip();


		cout << "    Check [I]nventory" << endl;
		cout << "    Go to [T]ower" << endl;
		cout << "        ->[E]arth" << endl;
		cout << "        ->[M]oon" << endl;
		cout << "        ->[V]enus" << endl;
		cout << "        ->M[A]rs" << endl;
		cout << "        ->[R]eef" << endl;
		
		cin >> answer;
		if (answer == 'i' || answer == 't' || answer == 'e' || answer == 'm' || answer == 'v' || answer == 'a' || answer == 'r')
		{
			moveOn = true;
			switch (answer)
			{
			case 'I':
			case 'i':
				Inventory();
				break;
			case 'T':
			case 't':
				Tower();
				break;
			case 'e':
			case 'E':
				Earth();
				break;
			case 'm':
			case 'M':
				Moon();
				break;
			case 'v':
			case 'V':
				Venus();
				break;
			case 'a':
			case 'A':
				Mars();
				break;
			default:
			case 'r':
			case 'R':
				break;
				//Orbit();

			}
		}
		else
		{
			cout << "Sorry but that is in invalid input, please try again" << endl;
		}
	}

}


void Earth()
{
	DrawWarp(false); // the bool is to tell if the ship is going up to orbit or going down to the planet from orbit
	system("CLS");
	string beginText = "Please select what you would like to do on Earth";
	bool leave = false;
	char answer;
	SlowPrint(beginText, 40);
	system("CLS");
	while (leave == false)
	{
		DrawSelectionMenu();
		cout << "\n";
		cin >> answer;
		switch (answer)
		{
		case 'o':
			Orbit();
			break;
		case 'i':
			Inventory();
			break;
		case 's':
			cout << "Sorry but Strikes on Earth are unavalible at this time" << endl; system("pause");//EarthStrike_List(); 
			break;
		case 'p':
			EarthPatrol();
			break;
		case 'b':
			//Earth_Bounties();
			break;
		}
		// I Inventory
		// O Orbit
		// S Strike
		// p Patrol
		// B Bounty
	}
	system("pause");
}

void Moon()
{
	DrawWarp(false); // the bool is to tell if the ship is going up to orbit or going down to the planet from orbit
	system("CLS");
	string beginText = "Please select what you would like to do on the Moon";
	bool leave = false;
	char answer;
	SlowPrint(beginText, 40);
	system("CLS");
	while (leave == false)
	{
		DrawSelectionMenu();
		cout << "\n";
		cin >> answer;
		switch (answer)
		{
		case 'o':
			Orbit();
			break;
		case 'i':
			Inventory();
			break;
		case 's':
			cout << "Sorry but Strikes on the Moon are unavalible at this time" << endl; system("pause");
			break;
		case 'p':
			MoonPatrol();
			break;
		case 'b':
			//Moon_Bounties();
			break;
		}
		// I Inventory
		// O Orbit
		// S Strike
		// p Patrol
		// B Bounty
	}
	system("pause");
}

void Venus()
{
	DrawWarp(false); // the bool is to tell if the ship is going up to orbit or going down to the planet from orbit
	system("CLS");
	string beginText = "Please select what you would like to do on Venus";
	bool leave = false;
	char answer;
	SlowPrint(beginText, 40);
	system("CLS");
	while (leave == false)
	{
		DrawSelectionMenu();
		cout << "\n";
		cin >> answer;
		switch (answer)
		{
		case 'o':
			Orbit();
			break;
		case 'i':
			Inventory();
			break;
		case 's':
			cout << "Sorry but Strikes on Venus are unavalible at this time" << endl; system("pause");//EarthStrike_List(); 
			break;
		case 'p':
			VenusPatrol();
			break;
		case 'b':
			//Earth_Bounties();
			break;
		}
		// I Inventory
		// O Orbit
		// S Strike
		// p Patrol
		// B Bounty
	}
	system("pause");
}

void Mars()
{
	DrawWarp(false); // the bool is to tell if the ship is going up to orbit or going down to the planet from orbit
	system("CLS");
	string beginText = "Please select what you would like to do on Mars";
	bool leave = false;
	char answer;
	SlowPrint(beginText, 40);
	system("CLS");
	while (leave == false)
	{
		DrawSelectionMenu();
		cout << "\n";
		cin >> answer;
		switch (answer)
		{
		case 'o':
			Orbit();
			break;
		case 'i':
			Inventory();
			break;
		case 's':
			cout << "Sorry but Strikes on Mars are unavalible at this time" << endl; system("pause");//EarthStrike_List(); 
			break;
		case 'p':
			MarsPatrol();
			break;
		case 'b':
			//Earth_Bounties();
			break;
		}
		// I Inventory
		// O Orbit
		// S Strike
		// p Patrol
		// B Bounty
	}
	system("pause");
}
