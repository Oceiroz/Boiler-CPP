// Boiler Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int thermoLow = 10;
int thermoHigh = 35;
bool isBoilerOn = false;
int roomTemp = 20;
int thermoSetting = 0;
bool programShutdown = false;

int GetInput(string inputMessage);
void SetTemp();

int main()
{
    SetTemp();
    if (roomTemp >= thermoSetting && isBoilerOn == true)
    {
        isBoilerOn = false;
        cout << "boiler is turned off" << endl;
    }
    else if (roomTemp <= thermoSetting && isBoilerOn == false)
    {
        isBoilerOn = true;
        cout << "boiler is turned on" << endl;
    }
}
int GetInput(string inputMessage)
{
    int userInput = 0;
    while (true)
    {
        cout << inputMessage << endl;
        string rawInput;
        getline(cin, rawInput);
        try
        {
            userInput = stoi(rawInput);
            break;
        }
        catch (exception)
        {
            cout << "this input is invalid" << endl;
        }
    }
    return userInput;
}
void SetTemp()
{
    while (true)
    {
        thermoSetting = GetInput("Set thermo temp");
        if (thermoSetting < thermoLow)
        {
            cout << "setting is too low" << endl;
        }
        else if (thermoSetting > thermoHigh)
        {
            cout << "setting is too high" << endl;
        }
        else
        {
            break;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
