#ifndef GPS_TOOL_H
#define GPS_TOOL_H

namespace Navigation
{

//40.21312
struct degreeD
{
    double  degree;
    char    ch;
};

//40° 26.12312'
struct degreeDM
{
    double  degree;
    double  minutes;
    char    ch;
};

//40° 26' 46"
struct degreeDMS
{
    double  degree;
    double  minutes;
    double  second;
    char    ch;
};

//----------------Latitude------------------------------------------
struct Latitude
{
    Latitude(double);

private:
    degreeD mPoint;
};

//----------------Longitude------------------------------------------
struct Longitude
{
    Longitude(double);

private:
    degreeD mPoint;
};

}

#endif // GPS_TOOL_H
