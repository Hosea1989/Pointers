//
//  main.cpp
//  Programming Quiz 10
//
//  Created by Damien Hosea on 9/21/19.
//  Copyright © 2019 Damien Hosea. All rights reserved.
// ___________________________________________________________
// This program asks the user to input a string.
// Once the string is entered, a menu will be displayed,
// giving the user options to:
// Count the vowels, consonants, both, enter a new string and exit.
//____________________________________________________________

#include <iostream>
#include <cctype>

using namespace std;

//_______FUNCTION_PROTOTYPES_____________________
int CountVowels(char *,  int ARRAY_SIZE);
int CountConsonants (char *, int ARRAY_SIZE);
void NewString (char *, int ARRAY_SIZE);
void ShowMenu();
//_______________________________________________

int main()
{
    //____VARIABLES_______________________________
    int user_choice; //will hold users choice
    //___MENU_OPTION_CONSTANTS____________________
    const int Vowel_Choice = 1;
    const int Constant_Choice = 2;
    const int Both_Vow_Con_Choice = 3;
    const int New_String_Choice = 4;
    const int Quit_Choice = 5;
    //__________________________________________
    
    const int ARRAY_SIZE = 61;// The size of an Array
    char UserString ; // A string to hold the users String
    
    
    cout << " \t\tWelcome to Vowels and/or Constants\t\n";
    cout << " \t-A-E-I-O-U-[PRESS ENTER TO CONTINUE]-A-E-I-O-U-\t\n";
    cin.get();
    cout << " Please Enter a string up to " << (ARRAY_SIZE - 1) << " characters..\n"
         << " and I will count the Vowels and/or Constants...\n "<<endl;
    
    cin.getline(&UserString, ARRAY_SIZE);
    
    do //A do/while loop that will keep the program running
    {
        ShowMenu();
        cin >> user_choice;
    
        while (user_choice < Vowel_Choice || user_choice > Quit_Choice)
        {
            cout << " Please Enter a valid input";
            cin >> user_choice;
        }
        
        if (user_choice != Quit_Choice)
        {
        switch (user_choice) // Switch statement for the Menu.
            {
            
        case Vowel_Choice:
                    cout << "\t\t_____[VOWELS]_____\t\n";
                    cout << "\nThere are " << CountVowels(&UserString, ARRAY_SIZE) << " vowel(s)\n";
            break;
            
        case Constant_Choice:
            cout << "\t\t_____[CONSONANTS]_____\t\n";
                    cout << "\nThere are " << CountConsonants(&UserString, ARRAY_SIZE) << " consonant(s)\n";
            break;
            
        case Both_Vow_Con_Choice:
            cout << "\t\t_____[VOWELS/CONSONANTS]_____\t\n";
                    cout << "_________________________________________\n";
                    cout << "\nThere are " << CountVowels(&UserString,ARRAY_SIZE)<< " vowel(s)\n";
                    cout << "\nThere are " << CountConsonants(&UserString,ARRAY_SIZE) <<
                    " consonant(s)\n";
                    cout << "________________________________________\n";
            break;
            
        case New_String_Choice:
                    NewString (&UserString, ARRAY_SIZE);
                    break;
                    
            }
        }
    }while(user_choice != Quit_Choice);
            return 0;
}
//__________________________________________________________
// SHOW MENU FUNCTION DEFINITION
//_________________________________________________________
    
void ShowMenu()
{
    cout << "\n\n--MENU--\n\n"; // display menu to user
    
    cout << "1) Count the number of vowels in the string\n";
    cout << "2) Count the number of consonants in the string\n";
    cout << "3) Count both the vowels and consonants in the string\n";
    cout << "4) Enter another string\n";
    cout << "5) Exit the program\n";
    
    cout << "\nEnter your choice: ";
    
}

//__________________________________________________________
// COUNT VOWELS FUNCTION DEFINITION
//_________________________________________________________
int CountVowels(char *UserString, int ARRAY_SIZE)
{
    int Vowels = 0;
    
    while (*UserString != '\0')
    {
        if (*UserString == 'a' || *UserString == 'e' || *UserString == 'i'
            || *UserString == 'o' || *UserString == 'u' || *UserString == 'A' || *UserString == 'E' || *UserString == 'I' || *UserString == 'O' || *UserString == 'U')
            ++Vowels;
        UserString++;
    }
    return Vowels;
}

//__________________________________________________________
// COUNT CONSONANTS FUNCTION DEFINITION
//_________________________________________________________
int CountConsonants(char *UserString, int ARRAY_SIZE)
{
    int Consonants_Counter = 0;
    
    while (*UserString != '\0' && !ispunct(*UserString))
    {
            if (!(*UserString == 'a' || *UserString == 'e' || *UserString == 'i'
                  || *UserString == 'o' || *UserString == 'u' || *UserString == 'A' || *UserString == 'E' || *UserString == 'I' || *UserString == 'O' || *UserString == 'U'))
                ++Consonants_Counter;
                UserString++;
                }
                return Consonants_Counter;
                }
//__________________________________________________________
// NEW STRING FUNCTION DEFINITION
//_________________________________________________________

void NewString(char *UserString, int ARRAY_SIZE)
{
    int counter = 0; // counter variable
    cout << "\nEnter a string no more than " << (ARRAY_SIZE - 1)
    << " characters in length\n";
    cin.ignore(61, '\n');
    cin.getline(UserString, ARRAY_SIZE);
    
    // displays the string the user entered
    cout << "\nThe string you entered is\n";
    while (UserString[counter] != '\0')
    {
        cout << UserString[counter];
    counter++;
    }
}

