#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchange.h"
#include "Global.h"
#include <iomanip>

using namespace std;

class clsMainScreen:protected clsScreen
{
private:
	enum enMainMenuOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
	};

	static short _ReadMainMenueOption(string firstNumber, string lastNumber)
	{
		string numberRange = firstNumber + " to " + lastNumber;
		cout << setw(37) << left << "" << "Choose what do you want to do? [ " << numberRange << " ] ? ";
        short Choice = clsInputValidate::ReadShortNumberBetween( stoi(firstNumber), stoi(lastNumber), "Enter Number between " + numberRange + " ? ");
		return Choice;
	}

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        
        clsClientListScreen::ShowClientsList();

    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();

    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterList();

    }

    static void _ShowCurrencyExchangesMenue()
    {
        

    }

    static void _Logout()
    {

        CurrentUser = clsUser::Find("", "");
    }

    static void _PerfromMainMenueOption(enMainMenuOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenuOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenuOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenuOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenuOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenuOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenuOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenuOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenuOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;        
        
        case enMainMenuOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangesMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenuOptions::eExit:
            system("cls");
            _Logout();
            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1]  Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2]  Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3]  Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4]  Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5]  Find Client.\n";
        cout << setw(37) << left << "" << "\t[6]  Transactions.\n";
        cout << setw(37) << left << "" << "\t[7]  Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8]  Login Register.\n";
        cout << setw(37) << left << "" << "\t[9]  Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenuOptions)_ReadMainMenueOption("1", "10"));
    }
};

