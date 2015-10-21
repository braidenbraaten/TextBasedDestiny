#include <iostream>
#include <cmath>
#include <Windows.h>
#include <mmsystem.h>
#include <ctime>
#include "OrbitLocs.h"
#include "PlayerStats.h"
#include "Enemies.h"
#include <string>
using namespace std;



void Orbit();
	
//to scale things with player level



//enum playerTypes {RWAA, HUNTER, WARLOCK, TITAN};

char HunterCreated[]  = "Hunter Created";
char WarlockCreated[] = "Warlock  Created";
char TitanCreated[]   = "Titan  Created";

int PubPlayerType = 0;
int PubPlayerLevel = 1;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



void DrawGhost()
{


	int timer = 500;
	int timer2 = 500;
	int timesPlayed = 4;
	if (timesPlayed > 0)
	{
		timer = 500;
		timer2 = 500;
		while (timer > 0)
		{
			cout << "      _" << endl;
			cout << "    _/_\\_ " << endl;
			cout << "   / \\_/ \\ " << endl;
			cout << "  /_ / \\ _\\ " << endl;
			cout << "< -_< O >_- >" << endl;
			cout << "  \\  \\_/\  /" << endl;
			cout << "   \\_/_\\_/" << endl;
			cout << "     \\_/ " << endl;
			--timer;
		}
		system("CLS");
		while (timer2 > 0)
		{
			cout << "      _" << endl;
			cout << "    _/_\\_ " << endl;
			cout << "   / \\_/ \\ " << endl;
			cout << "  /_ / \\ _\\ " << endl;
			cout << "< -_< - >_- >" << endl;
			cout << "  \\  \\_/\  /" << endl;
			cout << "   \\_/_\\_/" << endl;
			cout << "     \\_/ " << endl;
			--timer2;
		}
		system("CLS");
		--timesPlayed;
	}
	cout << "      _" << endl;
	cout << "    _/_\\_ " << endl;
	cout << "   / \\_/ \\ " << endl;
	cout << "  /_ / \\ _\\ " << endl;
	cout << "< -_< O >_- >" << endl;
	cout << "  \\  \\_/\  /" << endl;
	cout << "   \\_/_\\_/" << endl;
	cout << "     \\_/ " << endl;
}

void Timer(int setTimer, bool timerOn)
{
	if (timerOn == true)
	{
		bool redText = false;
		bool purpleText = false;
		bool blueText = false;
		int timerStart = setTimer;
		int timer = timerStart;
		bool timedOnce = false;
		bool showCharacterCreation = false;

		PlaySound(TEXT("Ghost.wav"), NULL, SND_ASYNC);

		while (timer > -3000 && timedOnce == false)
		{
			timer--;
			if (PubPlayerType == HUNTER) { redText = true; }
			if (PubPlayerType == WARLOCK) { purpleText = true; }
			if (PubPlayerType == TITAN) { blueText = true; }

			if (purpleText == true) { SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY)); }
			if (redText == true) { SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_RED)); }
			if (blueText == true) { SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_BLUE)); }

			if (timer <= 0 && timer > -1000) { system("CLS"); cout << "\t\t\t ...Initiating Guardian Protocal..."; }
			else if (timer <= -1000 && timer > -2000) { cout << "001001"; }
			else if (timer <= -2000 && timer > -3000) { system("CLS"); cout << "\t\t\t...booting Guardian..."; }
			else if (timer <= -3000) { timer = 1000; timedOnce = true; }

		}
		if (timedOnce == true)
		{
			PlaySound(NULL, 0, 0);
			PlaySound(TEXT("GhostWakeUp.wav"), NULL, SND_ASYNC);

			showCharacterCreation = true;

			if (showCharacterCreation == true)
			{
				switch (PlayerType(PubPlayerType))
				{
				case 1:

					system("CLS");
					DrawGhost();

					cout << "\t\t\t\t    [" << HunterCreated << "]" << endl;
					cout << "\t\t\t\t/ \\ ...__________... / \\    " << endl;
					cout << "\t\t\t\t/ \\ ...[Complete]... / \\    " << endl;
					cout << "\t\t\t\t/ \\ ...*   **   *... / \\    " << endl;
					cout << "\t\t\t\t        ___  ___       " << endl;
					cout << "\t\t\t\t       /  /  \\  \\    " << endl;
					cout << "\t\t\t\t      /  /    \\  \\   " << endl;
					cout << "\t\t\t\t     /__/      \\__\\  " << endl;
					cout << "\t\t\t\t        ___  ___       " << endl;
					cout << "\t\t\t\t       /  /  \\  \\    " << endl;
					cout << "\t\t\t\t      /  /    \\  \\   " << endl;
					cout << "\t\t\t\t     /__/      \\__\\  " << endl;
					cout << "\t\t\t\t        ___  ___       " << endl;
					cout << "\t\t\t\t       /  /  \\  \\    " << endl;
					cout << "\t\t\t\t      /  /    \\  \\   " << endl;
					cout << "\t\t\t\t     /__/      \\__\\  " << endl;

					//SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN));
					redText = false;
					break;
				case 2:

					system("CLS");
					DrawGhost();
					cout << "\t\t\t\t   [" << WarlockCreated << "] \a\b\b\b\b\b\b" << endl;
					cout << "\t\t\t\t/ \\ ...__________... / \\    " << endl;
					cout << "\t\t\t\t/ \\ ...[Complete]... / \\    " << endl;
					cout << "\t\t\t\t/ \\ ...*   **   *... / \\    " << endl;
					cout << "\t\t\t\t     /\\    /\\    /\\        " << endl;
					cout << "\t\t\t\t    /  \\  /  \\  /  \\       " << endl;
					cout << "\t\t\t\t   /   /  \\  /  \\   \\      " << endl;
					cout << "\t\t\t\t  /   / /\\ \\/ /\\ \\   \\   " << endl;
					cout << "\t\t\t\t /   / / / /\\ \\ \\ \\   \\  " << endl;
					cout << "\t\t\t\t/___/ /_/ /__\\ \\_\\ \\___\\ " << endl;
					break;
				case 3:

					system("CLS");
					DrawGhost();
					cout << "\t\t\t\t    [" << TitanCreated << "]" << endl;
					break;
				}
				showCharacterCreation = false;
			}

			timedOnce = false;
			SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN));
			purpleText = false;
		}
	}
}




int main()
{


	

	//Enemy comprised of a randomly picked FALLEN type enemy;
	Enemy enemy(FALLEN);
	
	srand(time(NULL));
	int RNG_Player = rand() % 25 + 1;
	PubPlayerType = Guardian.pType;
	system("pause");
	
	Timer(-500, true);
	system("pause");
	

	
	
	Tower(); // First -> into tower

	



	system("pause");
}
             
/*           

               Warlock Icon
              
			 /\    /\    /\
 			/  \  /  \  /  \
		   /   /  \  /  \   \
          /   / /\ \/ /\ \   \
         /   / / / /\ \ \ \   \
        /___/ /_/ /__\ \_\ \___\           

		Hunter Icon
	

   __________________     __________________   
  |    	___  ___     |   |     ___  ___     |
  |	   /  /  \  \    |   |	  /  /  \  \    |
  |   /  /    \  \   |   |   /  /    \  \   |
  |  /__/      \__\  |   |  /__/      \__\  |
  |     ___  ___     |   |     ___  ___     |
  |	   /  /  \  \    |   |	  /  /  \  \    |
  |	  /  /    \  \   |   |	 /  /    \  \   |
  |  /__/      \__\  |   |  /__/      \__\  |
  |	    ___  ___     |   |	   ___  ___     |
  |	   /  /  \  \    |   |	  /  /  \  \    |
  |	  /  /    \  \   |   |	 /  /    \  \   |
  |	 /__/      \__\  |   |	/__/      \__\  |
  |                  |   |                  |
  \                  /   \                  /
   \                /     \                /
    \              /       \              /
	 \____________/         \____________/

 
[Heavy Ammo]
			      _
			    _/_\_ 
			   / / \ \
	     	  <  (O)  >
		       \_\_/_/
			     \_/


				     _
				   _/_\_ 
				  / \_/ \
				 /_ / \ _\
			   < -_<(O)>_- >
				 \  \_/  /
				  \_/_\_/   
				    \_/



			             
				    \         /                               
    ______		    <--------->          ______                 
   / ___  \         /  \   /  \         /  ___ \                
  / /o o\  \_  _____   |   |   _____  _/  /o o\ \              
 < :[ O ]:   \/_=_=_\__\___/__/_=_=_\/   :[ O ]: >           
  \ \o_o/    /    ___  _____  ___    \    \o_o/ /            
   \	  __/    /  /{/_____\}\  \    \__      /             
    \____/  \   /__ \_       _/ __\   /  \____/ 
	  \/     \_/   \  \_____/  /   \_/     \/
	         / \    \_/=_=_=\_/    / \      
	     	          \_____/    
   			                
     
      |  
      |(), 
      |/ 
  ____|_________________
  \___\____\__|__/__/__/
   \___\____\_|_/__/__/
    \_________|______/
	   \      |    |
		\     |    |
	     \	  |    |
		  |	  |    |
	      |   |    |
		  |	  |    |
	      |	  |    |
		  |   |   /
		  |   |  /
		  |___|_/

		(         [ S E L E C T I O N   M E N U ]         )     
		___________________________________________________
	   /           \	 _________________     /           \
      /             \   *I N V E N T O R Y*   /             \
     /  ___________  \     ---[  I  ]---     /  ___________  \
	/  *S T R I K E*  \_____________________/  *P A T R O L*  \
	\   ---[ S ]---   /       _________     \  ---[  P  ]---  /
	 \               /       *O R B I T*     \               /
	  \             /       ---[  O  ]---     \             /
	   \___________/___________________________\___________/
		\_________\ \     _______________     / /_________/
		 \ \    / /  \_  *B O U N T I E S*  _/  \ \    / /
	      \ \__/ /     \   ---[  B  ]---   /     \ \__/ /
		   \/  \/       \_________________/       \/  \/


                                                       
                                                      ______________
                     ________________________________/ * O R B I T* \
         ___________/ [ I N V E N T O R Y  M E N U ] \_________ [O]_|  
        /---[ W ]---\______________/\________________/---[A]---\  / |   
       /     *W E A P O N S*               *A R M O R*          \/  |    
       |___________________________/\___________________________|   |   
	   |\    _________________    /\/\   ___________________   /|   |   
	   | \  *M A T E R I A L S*  /    \ *C O N S U M A B L E* / |   |
	   |  \     ---[ M ]---     /\    /\      ---[ C ]---    /  |   |
	   |   \___________________/  \  /  \___________________/   |  / 
	  /_\__/ *S E T T I N G S* \___\/___/    *S H I P S*    \__/_\/
      \_/  \___________________-[S]--[B]-___________________/  \_/
	   |_______/               \/  \/  \/               \_______|


                                                        L E V E L  U P 
                                                        _____    _____
                                                        \___/ __ \___/
                                                        /___\ \/ /___\
                                                            / /\ \
                                                           / /  \ \
                                                          /_/    \_\
                                                         L E V E L Guardian.getPlayerLevel()



*/             