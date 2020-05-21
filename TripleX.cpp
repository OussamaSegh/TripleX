// TripleX.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <ctime>

using namespace std;

void PrintIntroduction(int difficulty)
{
    cout << "\n You are a secret agent breaking into a LEVEL " << difficulty;
    cout << "\n secure server room ... \n Enter the correct code to continue ... \n\n";

}

bool gameLoop(int difficulty)
{
    PrintIntroduction(difficulty);

    //generate code

    const int A = rand() % difficulty + difficulty;
    const int B = rand() % difficulty + difficulty;
    const int C = rand() % difficulty + difficulty;

    cout << "there are three numbres in the code .... \n ";
    cout << "the codes add-up to : " << A + B + C << endl;
    cout << "the codes multiply to give : " << A * B * C << endl;

    //Store Player Guesses
    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;

    // check if player input is correct

    if ((A + B + C == GuessA + GuessB + GuessC) & (A * B * C == GuessA * GuessB * GuessC))
    {
        cout << "well Played Agent! Keep Going! \n\n";
        return true;
    }
    else
    {
        cout << "\n Sorry you entered the wrong codes :( \n";
        return false;
    }

}
int main()
{
    srand(time(NULL));//create a new random sequence based on current time
    int levelDifficulty = 1;
    int maxLevel = 5;
    bool b;
    // Game loop
        while (levelDifficulty <= maxLevel)
        {
            b = gameLoop(levelDifficulty);
            if (b) levelDifficulty++;
        }
}
