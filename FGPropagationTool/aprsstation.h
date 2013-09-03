#ifndef APRSSTATION_H
#define APRSSTATION_H

#include <QString>

class AprsStation
{
public:
    AprsStation();
    QString callsign;
    QString adressee;
    QString via;
    QString symbol;
    QString payload;
    double latitude;
    double longitude;
    QString getImage();
};

#endif // APRSSTATION_H