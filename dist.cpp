// distance computation algorithms comparison

#include <iostream>
#include <math.h>
#define d2r (3.1415926535897932384626433832795 / 180.0)

using namespace std;
float distance_between (float, float, float, float);
double haversine_km (double, double, double, double);
//double CalculateGreatCircleDistance(double, double, double, double, double);
double vincenty_distance(double, double, double, double);
int main()
{
    cout<<distance_between(50.566636,9.719217,50.566662,9.719659);
    cout<<endl;
    cout<<haversine_km(50.566636,9.719217,50.566662,9.719659)*1000; // great circle
    cout<<endl;
    //cout<< CalculateGreatCircleDistance(50.566636,9.719217,50.566662,9.719659, 6371); //great circle formula
    //cout<<endl;
    cout<< vincenty_distance(50.566636,9.719217,50.566662,9.719659); // great circle
    return 0;
}

float distance_between (float lat1, float long1, float lat2, float long2)
{
    // returns distance in meters between two positions, both specified
    // as signed decimal-degrees latitude and longitude. Uses great-circle
    // distance computation for hypothetical sphere of radius 6372795 meters.
    // Because Earth is no exact sphere, rounding errors may be up to 0.5%.
    // Courtesy of Maarten Lamers
    //tinyGPS
    float delta = d2r*(long1-long2);
    float sdlong = sin(delta);
    float cdlong = cos(delta);
    lat1 = d2r*lat1;
    lat2 = d2r*lat2;
    float slat1 = sin(lat1);
    float clat1 = cos(lat1);
    float slat2 = sin(lat2);
    float clat2 = cos(lat2);
    delta = (clat1 * slat2) - (slat1 * clat2 * cdlong);
    delta = delta*delta;
    delta += (clat2 * sdlong)*(clat2 * sdlong);
    delta = sqrt(delta);
    float denom = (slat1 * slat2) + (clat1 * clat2 * cdlong);
    delta = atan2(delta, denom);
    return delta * 6372795;
}




//calculate haversine distance for linear distance
double haversine_km(double lat1, double long1, double lat2, double long2)
{
    double dlong = (long2 - long1) * d2r;
    double dlat = (lat2 - lat1) * d2r;
    double a = pow(sin(dlat/2.0), 2) + cos(lat1*d2r) * cos(lat2*d2r) * pow(sin(dlong/2.0), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = 6367 * c;

    return d;
}

/*double CalculateGreatCircleDistance(double lat1, double long1, double lat2, double long2, double radius)
{
    return radius * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long2 - long1));
}*/

double vincenty_distance(double latitude1, double longitude1, double latitude2,
                         double longitude2)
{
    double lat1 = d2r*(latitude1);
    double lon1 = d2r*(longitude1);
    double lat2 = d2r*(latitude2);
    double lon2 = d2r*(longitude2);

    double d_lon = abs(lon1 - lon2);

    // Numerator
    double a = pow(cos(lat2) * sin(d_lon), 2);

    double b = cos(lat1) * sin(lat2);
    double c = sin(lat1) * cos(lat2) * cos(d_lon);
    double d = pow(b - c, 2);

    double e = sqrt(a + d);

    // Denominator
    double f = sin(lat1) * sin(lat2);
    double g = cos(lat1) * cos(lat2) * cos(d_lon);

    double h = f + g;

    double d_sigma = atan2(e, h);

    return 6372795 * d_sigma;
}
