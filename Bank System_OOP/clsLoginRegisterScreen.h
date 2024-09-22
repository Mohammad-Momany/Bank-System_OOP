#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

class clsLoginRegisterScreen :  protected clsScreen
{

private:
    static void _PrintRegisterRecordLine(clsUser::stLoginRegisterRecord  Register)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Register.Date;
        cout << "| " << setw(20) << left << Register.UserName;
        cout << "| " << setw(20) << left << Register.Password;
        cout << "| " << setw(20) << left << Register.Permissions;

    }

public:

    static void ShowLoginRegisterList()
    {
        vector <clsUser::stLoginRegisterRecord > vRegister = clsUser::GetRegistersList();

        string Title = "\t  Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vRegister.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(20) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vRegister.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord  Register : vRegister)
            {

                _PrintRegisterRecordLine(Register);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};
