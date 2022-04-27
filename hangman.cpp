#include <iostream>
#include <ctime>
using namespace std;

char country[10][15] = {"INDIA", "PAKISTAN", "CHINA", "NEPAL", "PANAMA", "NETHERLANDS", "ECUADOR", "RUSSIA", "JAPAN", "MALDIVES"};
char alphabets[27] = "QWERTYUIOPASDFGHJKLZXCVBNM";

time_t ttime = time(0);
tm *local_time = localtime(&ttime);

int noOfInpt = 1, ans = local_time->tm_sec % 10, wrong = 0, chances;
char inpt[30] = "", lvl;
bool printed = false, barPrinted = false, caught, repeat = false;


//*********Draw()function is called after every input to update the screen*************
void draw()
{
    system("cls");
    
    cout << "<---------------------------Guess The COUNTRY Name------------------------------>\n"
         << endl
         << "Country Name------>     ";

    barPrinted = false;
    caught = false;
    //this loop prints the blanks and correct guesses
    for (int i = 0; i < 15; i++)
    {
        printed = false;

        for (int j = 0; j < noOfInpt; j++)
        {
            if (inpt[j] == country[ans][i])
            {
                cout << "  " << inpt[j] << "  ";
                if (j == noOfInpt - 1)
                    caught = true;
                printed = true;
                break;
            }
        }

        if (printed == false && country[ans][i] != '\0')
        {
            cout << " ___ ";
            barPrinted = true;
        }
    }

    if (caught == false && repeat == false)
        wrong++;

    cout << "\n\n\n               Chances Left : " << chances - wrong << endl;
    cout << "\n\n               Remaining Letters : \n\n"
         << endl
         << "                     ";

    for (int i = 0; i < 26; i++)
    {
        caught = false;

        for (int j = 0; j < noOfInpt; j++)
        {
            if (inpt[j] == alphabets[i])
                caught = true;
        }

        if (i == 10)
            cout << "\n\n                       ";
        else if (i == 19)
            cout << "\n\n                          ";

        if (caught == true)
            cout << "   ";
        else
            cout << alphabets[i] << "  ";
    }

    cout << "\n\n\nEnter Current Guess LETTER here : ";
}


int main()
{
    system("cls");

    cout << "Chooes Level :\n     (H) Hard\n     (M) Medium\n     (E) Easy\n\n---->";
    cin >> lvl;
    lvl = toupper(lvl);

    switch (lvl)
    {
    case 'H':
        chances = 5;
        break;
    case 'M':
        chances = 10;
        break;
    case 'E':
        chances = 15;
        break;
    default:
        chances = 10;
    }

    draw();

    while (wrong != chances)
    {
        cin >> inpt[noOfInpt - 1];
        inpt[noOfInpt - 1] = toupper(inpt[noOfInpt - 1]);

        repeat = false;
        for (int j = 0; j < noOfInpt - 1; j++)
        {
            if (inpt[noOfInpt - 1] == inpt[j])
            {
                noOfInpt--;
                repeat = true;
                break;
            }
        }

        draw();

        if (barPrinted == false)
        {
            cout << "\n\n    ***********->>>>>>................ YOU WIN .............. <<<<<<-***********\n\ninput any letter to exit.";
            // cout<<"\n\n\n";
            // ltr.print(".you win.");
            // cout<<"\ninput any letter to exit.";
            cin >> inpt[30];
            return 0;
        }

        noOfInpt++;
    }

    cout << "\n\n   *******->>>>>>>> .............. YOU LOSE ................<<<<<<<<<<-*********\n"
         << "\n   Correct answer : " << country[ans] << "\ninput any letter to exit.";
        // cout<<"\n\n\n";
        // ltr.print(".you lose.");
    cin >> inpt[30];

    return 0;
}