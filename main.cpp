/*************************************************************************
** Author : Eric Trantham
** Program : HW5
** Date Created : December 7, 2021
** Date Last Modified : December 7, 2021
*************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <deque>
#include "listtools.h"
#include "listtools.cpp"

using namespace std;
struct Profile
{
    string fullname;
    string state;
    bool operator==( Profile rhs)
    {if (fullname==rhs.fullname) return true; return false; }
    bool operator!=(Profile rhs)
    {if (fullname!=rhs.fullname) return true; return false; }
};
ostream& operator<< (ostream &out, Profile &user)
{
    out << user.fullname<<"--" <<user.state;
    return out;
}

int main() {

    MyList<Profile> pMyList;
    Profile temp;
    string line;

    //let's practice file I/O
    ifstream file("/Users/trantham/CLionProjects/etrantha_HW5/presidentsWstates.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, temp.fullname, '\t');
            getline(ss, temp.state, '\t');
            pMyList.insertHead(temp);

        }
    }
    pMyList.deleteHead();
    temp.fullname = "Joseph Robinette Biden";
    temp.state = "PA";
    pMyList.insertHead(temp);
    temp.fullname = "James Carter";
    if(pMyList.search(temp))
    {
        cout<< "found: "<<temp<<endl;
    }
    else cout<<"Not Found"<<endl;
    cout<<"--------------"<<endl;
    pMyList.display(); //placed at the end cause I'm getting a SIGBUS error and the program exits. 

    return 0;
}

