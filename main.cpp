#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>  //"dynamic" arrays  {}
#include <iomanip>
#include <unistd.h> //sleep()
#include <stdlib.h>
using namespace std;

string picked_word;
string words[100];
int count_mistakes=0;

void pick_word()
{
    //pick a random word
    srand(time(NULL));
    int random_numeber = rand() % 100; //from 0 to 99
    picked_word = words[random_numeber];
    cout<<picked_word;
    //cout<<picked_word.length();
}

bool check_win(string *array1, string *array2ideal)
{
    int how_many = picked_word.length();
    int count1 = 0;
    for(int n = 0; n < picked_word.length(); n++)
    {
        if(array1[n] == array2ideal[n])
        {
            count1++;
        }
    }

    if(count1 == how_many)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void hangman(int m) //m - number of mistakes
{
    switch(m)
    {
        //head, body,left leg, right leg, left arm, right arm
        case 1:
        {
            cout<<" #########"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #     #####"<<endl;
            cout<<" #     #   #"<<endl;
            cout<<" #     #####"<<endl;
            cout<<" #"<<endl;
            cout<<" #"<<endl;
            cout<<" #"<<endl;
            cout<<" #"<<endl;
            cout<<" #"<<endl;
            cout<<"#  #"<<endl;
            break;
        }
        case 2:
        {
            cout<<" #########"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #     #####"<<endl;
            cout<<" #     #   #"<<endl;
            cout<<" #     #####"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #"<<endl;
            cout<<" #"<<endl;
            cout<<"#  #"<<endl;
            break;
        }
        case 3:
        {
            cout<<" #########"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #     #####"<<endl;
            cout<<" #     #   #"<<endl;
            cout<<" #     #####"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #      #"<<endl;
            cout<<" #     #"<<endl;
            cout<<"#  #"<<endl;
            break;
        }
        case 4:
        {
            cout<<" #########"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #     #####"<<endl;
            cout<<" #     #   #"<<endl;
            cout<<" #     #####"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #      # #"<<endl;
            cout<<" #     #   #"<<endl;
            cout<<"#  #"<<endl;
            break;
        }
        case 5:
        {
            cout<<" #########"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #     #####"<<endl;
            cout<<" #     #   #"<<endl;
            cout<<" #     #####"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #    ####"<<endl;
            cout<<" #    #  #"<<endl;
            cout<<" #      # #"<<endl;
            cout<<" #     #   #"<<endl;
            cout<<"#  #"<<endl;
            break;
        }
        case 6:
        {
            cout<<" #########"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #     #####"<<endl;
            cout<<" #     #   #"<<endl;
            cout<<" #     #####"<<endl;
            cout<<" #       #"<<endl;
            cout<<" #    #######"<<endl;
            cout<<" #    #  #  #"<<endl;
            cout<<" #      # #"<<endl;
            cout<<" #     #   #"<<endl;
            cout<<"#  #"<<endl;
            break;
        }
    }
}

void youre_dead()
{
    sleep(1.5);
    system("clear");
    cout<<" #########"<<endl;
    cout<<" #       #"<<endl;
    cout<<" #       #"<<endl;
    cout<<" #     #####"<<endl;
    cout<<" #     X   X"<<endl;
    cout<<" #     #####"<<endl;
    cout<<" #       #"<<endl;
    cout<<" #     ##### "<<endl;
    cout<<" #    #  #  #"<<endl;
    cout<<" #    #  #  #"<<endl;
    cout<<"# #     # #"<<endl;

    cout<<endl<<"\x1B[33mYou lost!\033[0m";
    cout<<endl<<"The word was: "<<picked_word;
}

void starting_page()
{
    system("clear");
    cout<<"\x1B[37mWelcome to Hangman!\033[0m"<<endl;
    cout<<" #########"<<endl;
    cout<<" #       #"<<endl;
    cout<<" #     #####"<<endl;
    cout<<" #     #   #"<<endl;
    cout<<" #     #####"<<endl;
    cout<<" #       #"<<endl;
    cout<<" #    #######"<<endl;
    cout<<" #    #  #  #"<<endl;
    cout<<" #      # #"<<endl;
    cout<<" #     #   #"<<endl;
    cout<<"#  #"<<endl;
    cout<<"Press ENTER to continue...";
}


int main()
{
    //working on the file
    fstream plik;
    plik.open("words_to_hangman.txt", ios::in);

    if(plik.good()==false)
    {
        cout<<"The file doesn't exist";
        exit(0);
    }

    string line;
    int nr_line=1;

    while(getline(plik, line))
    {
        if(nr_line<10)
        {
            line.erase(0,2);
            words[nr_line-1] = line;
            //cout<<line<<endl;
        }
        else if(nr_line<100)
        {
            line.erase(0,3);
            words[nr_line-1] = line;
            //cout<<line<<endl;
        }
        else
        {
            line.erase(0,4);
            words[nr_line-1] = line;
            //cout<<line<<endl;
        }

        //cout<<endl<<line;
        nr_line++;
    }
    //cout<<endl<<words[0]<<endl;


    string help;
    for(int i=0; i<100; i++)
    {
        //cout<<endl<<words[i];
        help = words[i];
        while(help[0] == ' ')
        {
            help.erase(0,1);
        }
        words[i] = help;
        //cout<<words[i]<<endl;
        //cout<<endl<<words[i];
    }

    //for some reason first word in the array doesn't change, chaniging manually
    words[0] = "time";

    //array containing 100 most popoular english nouns

    /*
    for(int i=0; i<100; i++)
    {
        cout<<endl<<words[i];
    }
    */

    plik.close();

    pick_word();

    //show a number of letters and an array for letters
    string word_letters[picked_word.length()];
    for(int i=0; i<picked_word.length(); i++)
    {
        word_letters[i] = '_';
        //cout<<word_letters[i]<<" ";
    }

    //how the finished array should look
    string word_letters_ideal[picked_word.length()];
    for(int i=0; i<picked_word.length(); i++)
    {
        word_letters_ideal[i] = picked_word[i]; //string[n]
        //cout<<word_letters_ideal[i]<<" ";
    }

    vector <char> wrong_letters;
    char your_pick;

    starting_page();
    getchar();
    system("clear");

    while(count_mistakes!=6)
    {
        //print wrong letters - elemenets in vector 'wrong_letters'
        for (size_t i = 0; i < wrong_letters.size(); ++i)
        {
            cout<<"\x1B[31m"<<wrong_letters.at(i)<<"\033[0m    ";
        }
        cout<<endl;

        //print hangman
        hangman(count_mistakes);

        cout<<"Your lives: ";
        for(int i=0; i<(6-count_mistakes); i++)
        {
            cout<<"\x1B[33m♥\033[0m\  ";
        }
        cout<<endl;

        for(int i=0; i<picked_word.length(); i++)
        {
            cout<<word_letters[i]<<" ";
        }
        cout<<endl<<"Enter the character you want to check: ";
        cin>>your_pick;

        //check if this is one of the word's letters
        bool good = false;
        for(int i=0; i<picked_word.length(); i++)
        {
            if(picked_word[i] == your_pick)
            {
                word_letters[i] = word_letters_ideal[i];
                good = true;
                //cout<<endl<<"eooo"<<endl;
            }
        }

        if(good == false)
        {
            wrong_letters.push_back(your_pick);
            count_mistakes++;
        }

        //win check

        if(check_win(word_letters, word_letters_ideal))
        {
            system("clear");
            /*
            for(int i=0; i<picked_word.length(); i++)
            {
                cout<<word_letters[i]<<" ";
            }
            */
            cout<<endl<<"\x1B[32mYou won!\033[0m";
            cout<<endl<<"The word was "<<picked_word;
            cout<<endl<<"You lost "<<count_mistakes<<" lives!"<<endl;
            hangman(count_mistakes);
            exit(0);
        }

        system("clear");
    }

    //lose
    hangman(count_mistakes);
    youre_dead();

    return 0;
}

// TODO (sebastian#1#): Jedna litera na raz - zabezpieczenie ..., mozna wpisywac cyfry
// TODO (sebastian#1#): Mozna wpisywac te same litery - napraw to ...
// TODO (sebastian#1#): Muzyka ...
// TODO (sebastian#1#): mierzenie czasu - na linuxie metoda z clock() dziala inaczej niz na widnowsie - nie korzystaj z niej ...
// TODO (sebastian#1#): mozliwosc powtorzenia gry ...





