#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;

class clsManageUsers :protected clsScreen
{


private:
    enum enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short ReadManageUsersMenueOption(string firstNumber, string lastNumber)
    {
        string numberRange = firstNumber + " to " + lastNumber;
        cout << setw(37) << left << "" << "Choose what do you want to do? [ " << numberRange << " ] ? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(stoi(firstNumber), stoi(lastNumber), "Enter Number between " + numberRange + " ? ");
        return Choice;
    }


    static void _ShowListUsersScreen()
    {
        cout << "\nShow List User Screen";
    }

    static void _ShowAddNewUserScreen()
    {
        cout << "\nShow Add New User Screen";
    }

    static void _ShowDeleteUserScreen()
    {
        cout << "\nShow Delete User Screen";
    }

    static void _ShowUpdateUserScreen()
    {
        cout << "\nShow Update User Screen";
    }

    static void _ShowFindUserScreen()
    {
        cout << "\nShow Find User Screen";
    }

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Manage User Menue...";
        system("pause>0");
        ShowManageUsersMenue();

    }

    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOptions)
    {
        switch (ManageUsersMenueOptions)
        {
        case enManageUsersMenueOptions::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }


        case enManageUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpldateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }


        case enManageUsersMenueOptions::eMainMenue:
        {

            //do nothing here the main screen will handle it :-) ;
        }
        }


    }



public:


    static void ShowManageUsersMenue()
    {


        system("cls");
        _DrawScreenHeader("\t\Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption("1", "6"));
    }

};
