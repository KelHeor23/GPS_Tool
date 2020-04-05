#include <iostream>
#include <gps_tool.h>

using namespace std;

int main()
{
    Navigation::Latitude lat(10.9988);
    Navigation::Longitude lon(-25.9988);

    cout << lat.point().degree << lat.point().ch << '\n';
    cout << lon.point().degree << lon.point().ch << '\n';
    return 0;
}
