#ifndef FLIGHTGEARPREFS_H
#define FLIGHTGEARPREFS_H

#include <QString>

class FlightgearPrefs
{
public:
    FlightgearPrefs();
    QString _fgfs_bin;
    QString _fgdata_path;
    QString _scenery_path;
    QString _aircraft;
    QString _airport;
    unsigned _use_clutter;
    unsigned _use_antenna_pattern;
};

#endif // FLIGHTGEARPREFS_H