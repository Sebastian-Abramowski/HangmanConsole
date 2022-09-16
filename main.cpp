#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string words[100];

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

    //for some reason first word in the array don't want to change, chaniging manually
    words[0] = "time";

    //array containing 100 most popoular english nouns

    /*
    for(int i=0; i<100; i++)
    {
        cout<<endl<<words[i];
    }
    */

    plik.close();

    return 0;
}
