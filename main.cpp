#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>  //"dynamic" arrays  {}
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
    cout<<picked_word<<endl;
    //cout<<picked_word.length();
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
        word_letters_ideal[i] = picked_word[i];
        //cout<<word_letters_ideal[i]<<" ";
    }

    vector <char> wrong_letters; //head, body,left leg, right leg, left arm, right arm


    char your_pick;
    while(count_mistakes!=6)
    {
        //print vectors
        cout<<"Your lives: "<<6-count_mistakes<<endl;


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
        system("clear");
    }

    return 0;
}
