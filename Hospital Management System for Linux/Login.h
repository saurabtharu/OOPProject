#include "secret.h"
#include<unistd.h>

void  askKey(){
    char pass[15];
    int countPass = 5;
    sleep(1);
    abc:
    cout << "\t\t\t\t\t\t\t\t------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM  " << endl;
    cout << "\t\t\t\t\t\t\t\t------------------------------"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t     LOGIN                  " << endl;
    cout << "\t\t\t\t\t\t\t\t------------------------------" << endl << endl;
    cout << "\t\t\t\t\t\t\t\tSecret Key of  Program: ";
    cin >> pass;
    cin.ignore();
    

    system("clear");
    cout << endl << endl << endl;

    if (strcmp(pass, key) == 0)
    {
        sleep(1);
        cout << "\n\t\t\t\t\t\t\t\tThe access is granted";
        cout << "\n\n\t\t\t\t\t\t\t  Press any key to continue . . . ";
        cin.get();
        cin.clear();
        sleep(1);
    }
    else{
        while (strcmp(pass,key) != 0 && countPass !=0 )
        {
            system("clear");
            sleep(1);
            cout << "\n\t\t\t\t\t\t\t\tThe invalid password!!\n";
            countPass--;
            cout << "\t\t\t\t\t\t\t\tYou have " << countPass << " chance to guess now." << endl << endl;
            
            if (countPass > 0){
                goto abc;
            }
            else{
              cout << "\t\t\t\t\t\t       You are kicked from the program due to over trying\n";
            }
        }
        exit(0);
    }

    cout << endl << endl;
}

