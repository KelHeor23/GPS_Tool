#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "gps_tool.h"

//------------------------------------------------------------------------------
struct sPoint2DRead
{
    double altitude;
    double longitude;
    string description;
};

ifstream &operator >>(ifstream &aFile, sPoint2DRead &aObj)
{
    aFile >> aObj.longitude;
    aFile.ignore(256, ',');
    aFile >> aObj.altitude;
    aFile.ignore(256, ' ');
    return aFile;
}

void read_data()
{
    ifstream file;
    file.open("d:\\tmp\\tracks.tr");

    if(!file)
        return;

    sPoint2DRead point;

    Navigation::TrackPoints2D track;

    while(!file.eof())
    {
        point = sPoint2DRead{0.,0.,""};
        file >> point;

        if(file.good())
            track.add(Navigation::Point2D{point.altitude, point.longitude});

        if(file.fail())
        {
            file.clear();
            break;
        }

        if(file.bad())
        {
            file.clear();
            break;
        }
    }

    file.close();
}


//--------эксперимент, удалить по необходимости----------------------------------------------------------------------
double get_cin_double()
{
    double res = 0.0;

    cin >> res;
    if(cin.fail())
    {
        cin.clear();
        bool isSkip = true;
        char ch = '\0';
        for(;isSkip;)
        {
            cin >> ch;
            if(isdigit(ch))
            {
                cin.unget();
                isSkip = false;
                break;
            }
            switch (ch)
            {
            case '-':
            case '+':
            case '.':
                cin.unget();
                isSkip = false;
                break;
            }
        }
        cin >> res;
    }
    return res;
}

int main()
{
    read_data();

    return 0;
}
