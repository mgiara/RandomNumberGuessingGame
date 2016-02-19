#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getAGuess;

bool validateInput (int guess)
{
    if(guess >= 0 && guess <= 100){
        return true;
    }
    else{
        return false;
    }
}


void repeatLoop (int randomNumberBetween0and100)
{
    bool correct = false;
    do
    {
        cout << "Guess a number: (between 0 and 100): ";
        int guess;
        cin >> guess;
        if (validateInput(guess))
        {
            if (guess < randomNumberBetween0and100)
            {
                cout << "Too low, try again.\n\n";
            }
            else if (guess > randomNumberBetween0and100)
            {
                cout << "Too high, try again.\n\n";
            }
            else
            {
                cout << "Congratulations, you did it!!\n\n";
                correct = true;
            }
        }
        else
        {
            cout << "A number.  Between 0 and 100.  It isn't that difficult.\n";
            correct = true;
        }
    }
    while (!correct);
}

bool playAgain()
{
    cout << "Would you like to play again (Y/N)? ";
    char yesNo;
    cin >> yesNo;
    if (yesNo == 'Y' || yesNo == 'y')
    {
        return true;
    }
    else if (yesNo == 'n' || yesNo == 'N')
    {
        return false;
    }
    else
    {
        cout << "It was y or n we were looking for...";
        cout << "You can't take a simple command.  I quit. \n\n";
        return false;
    }
}

int generateRandomNumber ()
{
    unsigned seed = time(0);
    srand(seed);
    int randomNumberBetween0and100 = rand() % 100;
    return randomNumberBetween0and100;
}

void charCtrick ()
{
    cout << "Type a single character and press <Enter> to quit. ";
    char c;
    cin >> c;
}

int main()
{
    bool repeat = true;
    while(repeat)
    {
        int randomNumberBetween0and100 = generateRandomNumber();
        repeatLoop(randomNumberBetween0and100);
        if (!playAgain())
        {
            repeat = false;
            charCtrick();
        }
        else
            ;
    }
    return 0;
}
