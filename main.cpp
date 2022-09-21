#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>  //'dynamic' arrays  {}
#include <iomanip>
#include <unistd.h> //sleep()
#include <stdlib.h>
#include <chrono> //measure time M1-M5
#include <algorithm> //count()
using namespace std;

string picked_word;
string words[100];
int count_mistakes=0;
chrono::time_point<chrono::system_clock> start, finish; //M1
int number_of_loop = 0;

void pick_word()
{
    //pick a random word
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
            cout<<"# #"<<endl;
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
            cout<<"# #"<<endl;
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
            cout<<"# #"<<endl;
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
            cout<<"# #"<<endl;
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
            cout<<"# #"<<endl;
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
            cout<<"# #"<<endl;
            break;
        }
    }
}

void youre_dead()
{
    sleep(1.5);
    cout << "\033[2J\033[1;1H";
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
    cout << "\033[2J\033[1;1H";
    cout<<setw(45)<<"\x1B[37mWelcome to Hangman!\033[0m"<<endl<<endl;
    cout<<"                     #########"<<endl;
    cout<<"                     #       #"<<endl;
    cout<<"                     #     #####"<<endl;
    cout<<"                     #     #   #"<<endl;
    cout<<"                     #     #####"<<endl;
    cout<<"                     #       #"<<endl;
    cout<<"                     #    #######"<<endl;
    cout<<"                     #    #  #  #"<<endl;
    cout<<"                     #      # #"<<endl;
    cout<<"                     #     #   #"<<endl;
    cout<<"                    # #"<<endl<<endl;
    cout<<setw(40)<<"Press ENTER to continue...";
}

//you could have used a normal char instead of an ascii number , it works though
bool show_letter(vector <char> vec, int num_ascii) //we dont have to work on original vector, its fine
{
    int hm = count(vec.begin(), vec.end(), char(num_ascii)); //it will be terminated before adding to the vector char(num_ascii), so if there is such a char in the vector, a user will be asked to give us input once again
    if(hm==1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//taking only one letter chars as inputs, before you could pass the program "eoeofkd" and it would have taken 'd'
void enter_your_pick(string &s, char &c, vector <char> ve)
{
    cout<<endl<<"Enter the character you want to check: ";
    cin>>s;

    if(s.length() != 1)
    {
        cout<<endl<<"Invalid input, try again!";
        enter_your_pick(s, c, ve);
    }

    //at this point s.length() must be equal to 1
    c = s[0]; //char
    //ASCII - 65-90 capital, small 97-122
    int ascii_nb = int(c);

    if(show_letter(ve, ascii_nb) == false)
    {
        cout<<endl<<"This letter has been already checked, try again!";
        enter_your_pick(s, c, ve);
    }


    //check if it is a letter

    if(ascii_nb>=97&&ascii_nb<=122)
    {
        c = char(ascii_nb);
    }
    else if(ascii_nb>=65&&ascii_nb<=90)
    {
        c = char(ascii_nb + 32);
    }
    else
    {
        cout<<endl<<"Invalid input, try again!";
        enter_your_pick(s, c, ve);
    }
}


int main()
{
    srand(time(NULL));

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

    char looping = 'y';
    do
    {
        number_of_loop++;
        count_mistakes = 0;
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
        string helping_hand;

        starting_page();
        getchar();
        /*
        if(number_of_loop>1)
        {
            getchar();
        }
        */
        cout << "\033[2J\033[1;1H";

        start = chrono::system_clock::now(); //M2
        while(count_mistakes!=6)
        {
            cout<<endl<<picked_word;
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

            enter_your_pick(helping_hand, your_pick, wrong_letters);

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
                cout << "\033[2J\033[1;1H";
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
                finish = chrono::system_clock::now(); //
                chrono::duration<double> elapsed_seconds = finish - start; //M4
                cout<<endl<<"This round lasted: " << elapsed_seconds.count() << "s\n"; //M5

                cout<<"Do you want to play again? 'y' or 'n' : ";
                cin>> looping;
                break;
            }

            cout << "\033[2J\033[1;1H";
        }

        //lose
        if(count_mistakes == 6)
        {
        hangman(count_mistakes);
        finish = chrono::system_clock::now(); //M4
        youre_dead();
        chrono::duration<double> elapsed_seconds = finish - start; //M4
        cout<<endl<<endl<<"This round lasted: " << elapsed_seconds.count() << "s\n"; //M5

        cout<<"Do you want to play again? 'y' or 'n' :";
        cin>>looping;
        }
    }
    while(looping == 'y');


    return 0;
}

// TODO (sebastian#1#): Muzyka ...

// system("clear") wasnt working properly -> cout << "\033[2J\033[1;1H";
// declaring again

// napraw inputa











