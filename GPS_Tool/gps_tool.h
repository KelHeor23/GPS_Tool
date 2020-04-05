#ifndef GPS_TOOL_H
#define GPS_TOOL_H

namespace Navigation
{
    struct degreeD  //формат хранения координат
    {
        double degree;
        char ch;
    };

    struct degreeDM  //формат хранения координат с минутами
    {
        double degree;
        double minutes;
        char ch;
    };

    struct degreeDMS //формат хранения координат с минутами и секундами
    {
        double degree;
        double minutes;
        double seconds;
        char ch;
    };
//-------------------------Latitude-------------------------------------------------------
    struct Latitude //широта
    {
        Latitude(double);
        Latitude(const Latitude &);
        Latitude &operator=(const Latitude &);

        Latitude &operator=(const Latitude &&) = delete;
        Latitude(const Latitude &&) = delete;

        bool operator==(const Latitude &) const;
        bool operator!=(const Latitude &) const;

        const degreeD &point() const;

    private:
        degreeD mPoint;
        void checkAndCorrect();
    };

//-------------------------Longitude-------------------------------------------------------

    struct Longitude //долгота
    {
        Longitude(double);
        Longitude(const Longitude &);
        Longitude &operator=(const Longitude &);

        Longitude &operator=(const Longitude &&) = delete;
        Longitude(const Longitude &&) = delete;

        bool operator==(const Longitude &) const;
        bool operator!=(const Longitude &) const;

        const degreeD &point() const;

    private:
        degreeD mPoint;
        void checkAndCorrect();
    };

//-------------------------Point2D-------------------------------------------------------

    struct Point2D
    {
        Point2D(double, double);
        Point2D(Latitude, Longitude);
        Point2D(const Point2D &);
        Point2D &operator=(const Point2D &);

        Point2D &operator=(const Point2D &&) = delete;
        Point2D(const Point2D &&) = delete;

        const Latitude &latitude() const;
        const Longitude &longitude() const;

        bool operator==(const Point2D &) const;
        bool operator!=(const Point2D &) const;

        double distanceTo(const Point2D &) const;
        double azimuteTo(const Point2D &) const;


    private:
        Latitude mLatitude;
        Longitude mLongitude;

    };

//-------------------------Common-------------------------------------------------------

    namespace common
    {
        bool latitudeIsCorrect(double);
        bool longitudeIsCorrect(double);

        double degreeToRadian(const double &);
        double toRadian(const Latitude &);
        double toRadian(const Longitude &);

        double radianToDegree(const double &);

        const degreeDM &toDM(const Latitude&) ;
        const degreeDM &toDM(const Longitude&);

        const degreeDMS &toDMS(const Latitude&);
        const degreeDMS &toDMS(const Longitude&);

        /* return minutes from degree */
        double minutes(const double&);
        double minutes(const Latitude&);
        double minutes(const Longitude&);

        /* return seconds from degree */
        double seconds(const double&);
        double seconds(const Latitude&);
        double seconds(const Longitude&);

        double courseAzimuth(const Point2D&, const Point2D&, const Point2D&); //
    }

//-------------------------Constants-------------------------------------------------------

    namespace constants //константы для корректного подсчета
    {
        constexpr double PI   = 3.141592653589793;
        constexpr double PI_2 = PI / 2.;
        constexpr double PI_4 = PI / 4.;

        constexpr double LatitudeRightRange = 90.0;
        constexpr double LatitudeLeftRange  = -90.0;

        constexpr double LongitudeRightRange = 180.0;
        constexpr double LongitudeLeftRange  = -180.0;

        constexpr double DegreeToRadianCoof = PI / 180.;
        constexpr double RadianToDegreeCoof = 180. / PI;

        constexpr double EarthRadiusM       = 6371001;
        constexpr double EarthRadiusKM      = 6371.001;

        constexpr double RadiusAtEquatorM   = 6378137;
        constexpr double RadiusAtEquatorKM  = 6378.137;

        constexpr double RadiusAtPoleM      = 6356752;
        constexpr double RadiusAtPoleKM     = 6356.752;
    }
}


#endif // GPS_TOOL_H
