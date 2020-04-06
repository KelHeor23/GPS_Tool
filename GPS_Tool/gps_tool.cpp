#include "gps_tool.h"

namespace Navigation
{

//----------------Latitude------------------------------------------

Latitude::Latitude(double degreeD)
    :mPoint{degreeD, 'S'}
{
    checkAndCorrect();
}

void Latitude::checkAndCorrect()
{
    if (!common::latitudeIsCorrect(mPoint.degree))
    {
        if (mPoint.degree >= 0.0)
            mPoint.degree = constants::LatitudeRightRange;
        else
            mPoint.degree = constants::LatitudeLeftRange;
    }
    mPoint.ch = (mPoint.degree >= 0) ? 'N' : 'S';
}

const degreeD &Latitude::point() const
{
    return mPoint;
}

Latitude::Latitude(const Latitude &other)
    :mPoint{other.mPoint.degree, other.mPoint.ch}
{

}

Latitude &Latitude::operator=(const Latitude &aObj)
{
    if(this == &aObj)
        return *this;
    this->mPoint.degree = aObj.mPoint.degree;
    this->mPoint.ch     = aObj.mPoint.ch;
    return *this;
}

bool Latitude::operator==(const Latitude &aRhs) const
{
    return this->mPoint.degree == aRhs.mPoint.degree;
}

bool Latitude::operator!=(const Latitude &aRhs) const
{
    return this->mPoint.degree != aRhs.mPoint.degree;
}


//----------------Longitude------------------------------------------
Longitude::Longitude(double degreeD)
    :mPoint{degreeD, 'E'}
{
    checkAndCorrect();
}

void Longitude::checkAndCorrect()
{
    if (!common::longitudeIsCorrect(mPoint.degree))
    {
        if (mPoint.degree >= 0.0)
            mPoint.degree = constants::LongitudeRightRange;
        else
            mPoint.degree = constants::LongitudeLeftRange;
    }
    mPoint.ch = (mPoint.degree >= 0) ? 'E' : 'W';
}

const degreeD &Longitude::point() const
{
    return mPoint;
}

Longitude::Longitude(const Longitude &other)
    :mPoint{other.mPoint.degree, other.mPoint.ch}
{

}

Longitude &Longitude::operator=(const Longitude &aObj)
{
    if(this == &aObj)
        return *this;
    this->mPoint.degree = aObj.mPoint.degree;
    this->mPoint.ch     = aObj.mPoint.ch;
    return *this;
}

bool Longitude::operator==(const Longitude &aRhs) const
{
    return this->mPoint.degree == aRhs.mPoint.degree;
}

bool Longitude::operator!=(const Longitude &aRhs) const
{
    return this->mPoint.degree != aRhs.mPoint.degree;
}

//----------------common------------------------------------------
namespace common
{
    bool latitudeIsCorrect(double aDegree)
    {
        return (aDegree >= constants::LatitudeLeftRange) && (aDegree <= constants::LatitudeRightRange);
    }

    bool longitudeIsCorrect(double aDegree)
    {
        return (aDegree >= constants::LongitudeLeftRange) && (aDegree <= constants::LongitudeRightRange);
    }
}
}
