#include <iostream>
#include <stdio.h>
#include <fstream>
#include <Windows.h>
#include <WinBase.h>

using namespace std;

int main(int argc, char *argv[])
{
    int i;
    string arg;
    const char* empty = " ";

    for (i = 1; i < argc; i++)
    {
        arg += argv[i] + string(empty);
    }

    string s(arg.substr(0, arg.size() - 1) + ".exe");
    ofstream outfile(s);
    outfile << "0" << std::endl;
    outfile.close();

    ShellExecute(NULL, "runas", s.c_str(), NULL, NULL, SW_SHOWNORMAL);
    remove(s.c_str());
}
