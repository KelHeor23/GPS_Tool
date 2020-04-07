#include <iostream>
#include <gps_tool.h>

using namespace std;

int main()
{
    /*Navigation::Latitude lat(10.9988);
    Navigation::Longitude lon(-25.9988);

    cout << lat.point().degree << lat.point().ch << '\n';
    cout << lon.point().degree << lon.point().ch << '\n';*/

    Navigation::Point2D p1(55.814048, 37.359538);
    Navigation::Point2D p2(55.823586, 37.375473);
    Navigation::Point2D p3(55.826773, 37.368652);
    Navigation::Point2D p4(55.823627, 37.376267);


    cout << p1.azimuteTo(p2) << endl;
    cout << p1.distanceTo(p2) << endl;

    cout << p2.azimuteTo(p4) << endl;
    cout << p2.distanceTo(p4) << endl;

    //cout << Navigation::common::courseAzimuth(p1, p2, p4) << endl;

    /*55.814048
    37.359538

    55.823586,
    37.375473

    55.826773,
    37.368652

    55.823627,
37.376267
    */
    return 0;
}
