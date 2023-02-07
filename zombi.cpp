#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;

int createZombie()
{
    if (rand() % 67 < 10)
    return 0;

    else
    return rand() % 20 + 1;
}

int main()
{
    srand(time(NULL));
    char enter;

    // game stats
    int playerAlive = true;
    int playerSkill =rand() % (20 - 10) + 10;
    int playerscore = 0;
    string playername = "";
    int zombieCount = 0;
    int zombiesKilled = 0;

	string tire = "________________________________________________________________________________________________________________________";//for codes beauty
	string space="\t\t\t\t";//for code's beauty
	
	//Tittle
    cout << space << "Welcome to Zombie War\3\6\4\5\n" << tire;
	cout << "Press [ENTER] to start.";
    cin.get();
    system("cls");
    cout << space << "Welcome to Zombie War\3\6\4\5\n" << tire;
    
	//Description
    cout << "\t\t" << "Point system\n" << "for injuring zombie: 0.5" << endl;
    cout << "for seriously wounding zombie: 2" << endl << "for killing zombie: 5" << endl;
	cout << tire <<"some zombies are from left 4 dead\n" <<tire;
    
    //begining
    cout << "Please enter your name: ";
    cin >> playername;
    
    cout << playername << " Your skill is: " << playerSkill << endl;


    cout << "How many zombies do you wish to fight? ";
    cin >> zombieCount;
    system("cls");// for beauty
	if (zombieCount > 10)
	{
		cout << "I see you are fearless warrior" << endl << tire;
	}
    cout << "Get ready to fight for your life and good luck " << playername << "!" << endl << endl;

    // main game
    while (playerAlive && zombiesKilled < zombieCount)
	{
        // create a random zombie
        int zombieSkill = createZombie();

        // battle sequence
        if (zombieSkill > 18)//tank from left 4 dead
		{
            cout << endl << "Here comes a tank zombie!" << endl;
            playerscore = playerscore + 15;
        }
        
        else if (zombieSkill > 16)//witch from left 4 dead
		{
			cout << endl << "Be careful there is witch!!!" << endl;
			sleep(2);
			cout << "she heard you, here she comes"	<< endl;
			playerscore = playerscore + 10;
		}
		
		else if (zombieSkill > 14)//smoker from left 4 dead
		{
			cout << "Be careful i heard smoker" << endl;
			sleep(2);
			for(int i = 0; i < 120; i++)//for beauty
			{
        		cout << "_";
    		}
			cout << "SYSTEM" << endl;
			for(int i = 0; i < 120; i++)//for beauty
				{
        			cout << "_";
    			}
			cout << "smoker catched you" << endl;
			playerscore = playerscore + 8;
		}
		
		else if ( zombieSkill >12)//hunter from left 4 dead
		{
			cout << "i saw hunter jumping be careful" << endl;
			sleep(1);
			cout << "here he comes" << endl;
			playerscore = playerscore + 6;
		}
		
        else//common zombie
		{
            cout << endl << "Here comes zombie " << zombiesKilled + 1 << endl;
        }

        cout << "Fighting..." << endl;
        sleep(2);
		
		//test zombie skill
		//cout<<endl<<zombieSkill<<endl;
	
		
        // player died
        if (playerSkill < zombieSkill)
		{
            playerAlive = false;
            cout << "You have died." << endl;
        }

        // action with zombie
        else {
            if (playerSkill - zombieSkill > 7)
			{
				cout << "You killed the zombie!" << endl;
                playerscore = playerscore + 5;
            }
            else if (playerSkill - zombieSkill > 5)
			{
                cout << "You seriously wounded the zombie!" << endl;
                playerscore = playerscore + 2;
            }
            else if (playerSkill - zombieSkill > 3)
			{
                cout << "You cut off the limbs but the zombie is still alive!" << endl;
                playerscore = playerscore + 0.5;
            }
            else if (playerSkill - zombieSkill == 0)
			{
                cout << "You killed the zombie, but suffered injuries." << endl;
                playerscore = playerscore - 1;
            }
            zombiesKilled++;
        }
        cout << endl;
        sleep(1);
    }

    // end game
    if (zombiesKilled == zombieCount)
	{
        // victory
        cout << "You have survived this war!" << endl;
    }
    else
	{
        // loose
        cout << "You did not survive the zombie war." << endl;

    }

    cout << "Zombies outlived: " << zombiesKilled << endl;
    cout << "Final score: " << playerscore << endl << endl;
}
