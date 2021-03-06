// Written by Adrian Musceac YO8RZZ at gmail dot com, started August 2013.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#include "databaseapi.h"


DatabaseApi::DatabaseApi()
{
    _db =  QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("propagation.sqlite");
    if(!_db.open())
    {
        qDebug() << "Could not connect to database!";
    }
}

DatabaseApi::~DatabaseApi()
{
    _db.close();
}


QVector<AprsStation *>
DatabaseApi::older_positions(QString &callsign, int time)
{
    QVector<AprsStation *> stations;
    QSqlQuery query(_db);
    query.prepare("SELECT * FROM aprs_stations WHERE callsign=:callsign AND time_seen<:time ORDER BY time_seen DESC");
    query.bindValue(":callsign", callsign);
    query.bindValue(":time", time);
    query.exec();

    int callsign_idx = query.record().indexOf("callsign");
    int adressee_idx = query.record().indexOf("adressee");
    int via_idx = query.record().indexOf("via");
    int symbol_idx = query.record().indexOf("symbol");
    int payload_idx = query.record().indexOf("payload");
    int message_idx = query.record().indexOf("message");
    int latitude_idx = query.record().indexOf("latitude");
    int longitude_idx = query.record().indexOf("longitude");
    int time_seen_idx = query.record().indexOf("time_seen");


    while(query.next())
    {
        AprsStation *s = new AprsStation;
        s->callsign = query.value(callsign_idx).toString();
        s->adressee = query.value(adressee_idx).toString();
        s->via = query.value(via_idx).toString();
        s->symbol = query.value(symbol_idx).toString();
        s->payload = query.value(payload_idx).toString();
        s->message = query.value(message_idx).toString();
        s->latitude = query.value(latitude_idx).toDouble();
        s->longitude = query.value(longitude_idx).toDouble();
        s->time_seen = query.value(time_seen_idx).toInt();

        stations.push_back(s);
    }
    return stations;
}


QVector<AprsStation *>
DatabaseApi::similar_stations(QString &callsign, int time)
{
    QVector<AprsStation *> stations;
    QSqlQuery query(_db);
    query.prepare("SELECT * FROM aprs_stations WHERE callsign=:callsign AND time_seen>=:time ORDER BY time_seen ASC");
    query.bindValue(":callsign", callsign);
    query.bindValue(":time", time);
    query.exec();

    int callsign_idx = query.record().indexOf("callsign");
    int adressee_idx = query.record().indexOf("adressee");
    int via_idx = query.record().indexOf("via");
    int symbol_idx = query.record().indexOf("symbol");
    int payload_idx = query.record().indexOf("payload");
    int message_idx = query.record().indexOf("message");
    int latitude_idx = query.record().indexOf("latitude");
    int longitude_idx = query.record().indexOf("longitude");
    int time_seen_idx = query.record().indexOf("time_seen");


    while(query.next())
    {
        AprsStation *s = new AprsStation;
        s->callsign = query.value(callsign_idx).toString();
        s->adressee = query.value(adressee_idx).toString();
        s->via = query.value(via_idx).toString();
        s->symbol = query.value(symbol_idx).toString();
        s->payload = query.value(payload_idx).toString();
        s->message = query.value(message_idx).toString();
        s->latitude = query.value(latitude_idx).toDouble();
        s->longitude = query.value(longitude_idx).toDouble();
        s->time_seen = query.value(time_seen_idx).toInt();

        stations.push_back(s);
    }
    return stations;
}


QVector<AprsStation *>
DatabaseApi::filter_aprs_stations(int time)
{
    QVector<AprsStation *> stations;
    QSqlQuery query(_db);
    query.prepare("SELECT * FROM aprs_stations WHERE time_seen >=:time ORDER BY time_seen,id DESC");
    query.bindValue(":time", time);
    query.exec();

    int callsign_idx = query.record().indexOf("callsign");
    int adressee_idx = query.record().indexOf("adressee");
    int via_idx = query.record().indexOf("via");
    int symbol_idx = query.record().indexOf("symbol");
    int payload_idx = query.record().indexOf("payload");
    int message_idx = query.record().indexOf("message");
    int latitude_idx = query.record().indexOf("latitude");
    int longitude_idx = query.record().indexOf("longitude");
    int time_seen_idx = query.record().indexOf("time_seen");


    while(query.next())
    {
        AprsStation *s = new AprsStation;
        s->callsign = query.value(callsign_idx).toString();
        s->adressee = query.value(adressee_idx).toString();
        s->via = query.value(via_idx).toString();
        s->symbol = query.value(symbol_idx).toString();
        s->payload = query.value(payload_idx).toString();
        s->message = query.value(message_idx).toString();
        s->latitude = query.value(latitude_idx).toDouble();
        s->longitude = query.value(longitude_idx).toDouble();
        s->time_seen = query.value(time_seen_idx).toInt();

        stations.push_back(s);
    }
    return stations;
}

QVector<AprsStation *>
DatabaseApi::select_aprs_stations()
{
    QVector<AprsStation *> stations;
    QSqlQuery query(_db);
    query.prepare("SELECT * FROM aprs_stations ORDER BY time_seen,id DESC");
    query.exec();

    int callsign_idx = query.record().indexOf("callsign");
    int adressee_idx = query.record().indexOf("adressee");
    int via_idx = query.record().indexOf("via");
    int symbol_idx = query.record().indexOf("symbol");
    int payload_idx = query.record().indexOf("payload");
    int message_idx = query.record().indexOf("message");
    int latitude_idx = query.record().indexOf("latitude");
    int longitude_idx = query.record().indexOf("longitude");
    int time_seen_idx = query.record().indexOf("time_seen");


    while(query.next())
    {
        AprsStation *s = new AprsStation;
        s->callsign = query.value(callsign_idx).toString();
        s->adressee = query.value(adressee_idx).toString();
        s->via = query.value(via_idx).toString();
        s->symbol = query.value(symbol_idx).toString();
        s->payload = query.value(payload_idx).toString();
        s->message = query.value(message_idx).toString();
        s->latitude = query.value(latitude_idx).toDouble();
        s->longitude = query.value(longitude_idx).toDouble();
        s->time_seen = query.value(time_seen_idx).toInt();

        stations.push_back(s);
    }
    return stations;
}

QVector<AprsStation *>
DatabaseApi::filter_aprs_station(QString prefix)
{
    QVector<AprsStation *> stations;
    QSqlQuery query(_db);
    query.prepare("SELECT * FROM aprs_stations WHERE callsign LIKE :callsign ORDER BY time_seen,id DESC");
    query.bindValue(":callsign", prefix+"%");
    query.exec();

    int callsign_idx = query.record().indexOf("callsign");
    int adressee_idx = query.record().indexOf("adressee");
    int via_idx = query.record().indexOf("via");
    int symbol_idx = query.record().indexOf("symbol");
    int payload_idx = query.record().indexOf("payload");
    int message_idx = query.record().indexOf("message");
    int latitude_idx = query.record().indexOf("latitude");
    int longitude_idx = query.record().indexOf("longitude");
    int time_seen_idx = query.record().indexOf("time_seen");


    while(query.next())
    {
        AprsStation *s = new AprsStation;
        s->callsign = query.value(callsign_idx).toString();
        s->adressee = query.value(adressee_idx).toString();
        s->via = query.value(via_idx).toString();
        s->symbol = query.value(symbol_idx).toString();
        s->payload = query.value(payload_idx).toString();
        s->message = query.value(message_idx).toString();
        s->latitude = query.value(latitude_idx).toDouble();
        s->longitude = query.value(longitude_idx).toDouble();
        s->time_seen = query.value(time_seen_idx).toInt();

        stations.push_back(s);
    }
    return stations;
}


void
DatabaseApi::update_aprs_stations(AprsStation * s)
{
    int id = -1;
    QSqlQuery query(_db);
    QSqlQuery query2(_db);
    query2.prepare("SELECT * FROM aprs_stations WHERE callsign=:callsign");
    query2.bindValue(":callsign", s->callsign);
    query2.exec();
    if(query2.size()>0)
    {
        int latitude_idx = query2.record().indexOf("latitude");
        int longitude_idx = query2.record().indexOf("longitude");
        int id_idx = query2.record().indexOf("id");

        while(query2.next())
        {
            double latitude = query2.value(latitude_idx).toDouble();
            double longitude = query2.value(longitude_idx).toDouble();
            if( (fabs( latitude - s->latitude) <= 0.001) && (fabs(longitude - s->longitude) <= 0.001))
            {
                id = query2.value(id_idx).toInt();
                break;
            }
        }
    }
    if(id!=-1)
    {
        query.prepare("UPDATE aprs_stations SET adressee=:adressee, via=:via,"
                       "symbol=:symbol, payload=:payload, "
                       "message=:message, "
                       "time_seen=:time_seen"
                       "WHERE id=:id ");
        query.bindValue(":adressee", s->adressee);
        query.bindValue(":via", s->via);
        query.bindValue(":symbol", s->symbol);
        query.bindValue(":payload", s->payload);
        query.bindValue(":message", s->message);
        query.bindValue(":time_seen", s->time_seen);
        query.bindValue(":id", id);
        query.exec();

    }
    else
    {
        query.prepare("INSERT INTO aprs_stations (callsign, adressee,"
                       "via, symbol, "
                       "payload, "
                       "message, latitude,"
                       "longitude, time_seen) VALUES (:callsign,"
                      ":adressee,:via,:symbol,"
                      ":payload,:message,"
                      ":latitude,:longitude, :time_seen)");
        query.bindValue(":callsign", s->callsign);
        query.bindValue(":adressee", s->adressee);
        query.bindValue(":via", s->via);
        query.bindValue(":symbol", s->symbol);
        query.bindValue(":payload", s->payload);
        query.bindValue(":message", s->message);
        query.bindValue(":latitude", s->latitude);
        query.bindValue(":longitude", s->longitude);
        query.bindValue(":time_seen", s->time_seen);
        query.exec();

    }

}

bool
DatabaseApi::select_commands(const unsigned &id_session)
{
    QSqlQuery query(_db);
    query.prepare("SELECT * FROM commands WHERE id_session=:id_session LIMIT 1");
    query.bindValue(":id_session", id_session);
    query.exec();
    int update_signals_idx = query.record().indexOf("update_signals");
    query.next();
    QString command = query.value(update_signals_idx).toString();
    if (command=="false")
        return false;
    else
        return true;
}

QVector<FlightgearPrefs *>
DatabaseApi::select_prefs()
{
    QVector<FlightgearPrefs *> prefs;
    QSqlQuery query(_db);
    query.prepare("SELECT * FROM fgfs_settings WHERE id=1");
    query.exec();

    int fgfs_binary_idx = query.record().indexOf("fgfs_binary");
    int fgdata_path_idx = query.record().indexOf("fgdata_path");
    int aircraft_idx = query.record().indexOf("aircraft");
    int airport_idx = query.record().indexOf("airport");
    int scenery_path_idx = query.record().indexOf("scenery_path");
    int srtm_path_idx = query.record().indexOf("srtm_path");
    int shapefile_path_idx = query.record().indexOf("shapefile_path");
    int use_clutter_idx = query.record().indexOf("use_clutter");
    int use_ITWOM_idx = query.record().indexOf("use_ITWOM");
    int scale_with_distance_idx = query.record().indexOf("scale_with_distance");
    int itm_performance_idx = query.record().indexOf("itm_performance_mode");
    int use_antenna_pattern_idx = query.record().indexOf("use_antenna_pattern");
    int windowX_idx = query.record().indexOf("windowX");
    int windowY_idx = query.record().indexOf("windowY");
    int aprs_server_idx = query.record().indexOf("aprs_server");
    int aprs_filter_range_idx = query.record().indexOf("aprs_filter_range");
    int plot_range_idx = query.record().indexOf("plot_range");
    while(query.next())
    {
        FlightgearPrefs *p = new FlightgearPrefs;
        p->_fgfs_bin = query.value(fgfs_binary_idx).toString();
        p->_fgdata_path = query.value(fgdata_path_idx).toString();
        p->_scenery_path = query.value(scenery_path_idx).toString();
        p->_aircraft = query.value(aircraft_idx).toString();
        p->_airport = query.value(airport_idx).toString();
        p->_srtm_path = query.value(srtm_path_idx).toString();
        p->_shapefile_path = query.value(shapefile_path_idx).toString();
        p->_use_clutter = query.value(use_clutter_idx).toInt();
        p->_use_ITWOM = query.value(use_ITWOM_idx).toInt();
        p->_scale_with_distance = query.value(scale_with_distance_idx).toInt();
        p->_itm_radio_performance = query.value(itm_performance_idx).toInt();
        p->_use_antenna_pattern = query.value(use_antenna_pattern_idx).toInt();
        p->_windowX = query.value(windowX_idx).toInt();
        p->_windowY = query.value(windowY_idx).toInt();
        p->_aprs_server = query.value(aprs_server_idx).toString();
        p->_aprs_filter_range = query.value(aprs_filter_range_idx).toInt();
        p->_plot_range = query.value(plot_range_idx).toInt();
        prefs.push_back(p);
    }
    return prefs;
}

void
DatabaseApi::savePrefs(FlightgearPrefs *p)
{
    QSqlQuery query(_db);
    query.prepare("UPDATE fgfs_settings SET "
                  "fgfs_binary =:fgfs_binary, fgdata_path=:fgdata_path, "
                  "scenery_path = :scenery_path, srtm_path=:srtm_path, shapefile_path=:shapefile_path, "
                  "aircraft=:aircraft, "
                  "airport = :airport, use_clutter= :use_clutter, use_ITWOM= :use_ITWOM, "
                  "itm_performance_mode=:itm_performance, "
                  "scale_with_distance=:scale_with_distance, "
                  "use_antenna_pattern = :use_antenna_pattern, windowX= :windowX, windowY= :windowY, "
                  "aprs_server= :aprs_server, aprs_filter_range=:aprs_filter_range, plot_range=:plot_range "
                  " WHERE id=1");
    query.bindValue(":fgfs_binary", p->_fgfs_bin);
    query.bindValue(":fgdata_path", p->_fgdata_path);
    query.bindValue(":scenery_path", p->_scenery_path);
    query.bindValue(":aircraft", p->_aircraft);
    query.bindValue(":airport", p->_airport);
    query.bindValue(":srtm_path", p->_srtm_path);
    query.bindValue(":shapefile_path", p->_shapefile_path);
    query.bindValue(":use_clutter", p->_use_clutter);
    query.bindValue(":use_ITWOM", p->_use_ITWOM);
    query.bindValue(":scale_with_distance", p->_scale_with_distance);
    query.bindValue(":itm_performance", p->_itm_radio_performance);
    query.bindValue(":use_antenna_pattern", p->_use_antenna_pattern);
    query.bindValue(":windowX", p->_windowX);
    query.bindValue(":windowY", p->_windowY);
    query.bindValue(":aprs_server", p->_aprs_server);
    query.bindValue(":aprs_filter_range", p->_aprs_filter_range);
    query.bindValue(":plot_range", p->_plot_range);
    query.exec();
}

QVector<Signal *>
DatabaseApi::select_signals(const unsigned &id_session)
{
    QVector<Signal *> station_signals;
    QSqlQuery query(_db);
    query.prepare("SELECT * FROM signals LEFT JOIN ground_stations ON signals.id_station=ground_stations.id"
                   "WHERE ground_stations.id!='' AND signals.id_session=:id_session");
    query.bindValue(":id_session", id_session);
    query.exec();

    int name_idx = query.record().indexOf("name");
    int frequency_idx = query.record().indexOf("frequency");
    int signal_dbm_idx = query.record().indexOf("signal_dbm");
    int signal_idx = query.record().indexOf("signal");
    int field_strength_uv_idx = query.record().indexOf("field_strength_uv");
    int link_budget_idx = query.record().indexOf("link_budget");
    int terrain_attenuation_idx = query.record().indexOf("terrain_attenuation");
    int clutter_attenuation_idx = query.record().indexOf("clutter_attenuation");
    int prop_mode_idx = query.record().indexOf("prop_mode");
    while(query.next())
    {
        Signal *s = new Signal;
        s->station_name = query.value(name_idx).toString();
        s->frequency = query.value(frequency_idx).toDouble();
        s->signal_dbm = query.value(signal_dbm_idx).toDouble();
        s->signal = query.value(signal_idx).toDouble();
        s->field_strength_uv = query.value(field_strength_uv_idx).toDouble();
        s->link_budget = query.value(link_budget_idx).toDouble();
        s->terrain_attenuation = query.value(terrain_attenuation_idx).toDouble();
        s->clutter_attenuation = query.value(clutter_attenuation_idx).toDouble();
        s->prop_mode = query.value(prop_mode_idx).toString();
        station_signals.push_back(s);
    }
    return station_signals;
}


void
DatabaseApi::update_signals(const unsigned &id_station, const unsigned &id_session, const Signal * s)
{
    QSqlQuery query(_db);
    QSqlQuery query2(_db);
    query2.prepare("SELECT * FROM signals WHERE id_station=:id_station");
    query2.bindValue(":id_station", id_station);
    query2.exec();
    if(query2.size()>0)
    {
        query.prepare("UPDATE signals SET signal_dbm=:signal_dbm, signal=:signal,"
                       "field_strength_uv=:field_strength_uv, link_budget=:link_budget, "
                       "terrain_attenuation=:terrain_attenuation, "
                       "clutter_attenuation=:clutter_attenuation, prop_mode=:prop_mode"
                       "WHERE id_session=:id_session AND id_station=:id_station");
        query.bindValue(":signal_dbm", s->signal_dbm);
        query.bindValue(":signal", s->signal);
        query.bindValue(":field_strength_uv", s->field_strength_uv);
        query.bindValue(":link_budget", s->link_budget);
        query.bindValue(":terrain_attenuation", s->terrain_attenuation);
        query.bindValue(":clutter_attenuation", s->clutter_attenuation);
        query.bindValue(":prop_mode", s->prop_mode);
        query.bindValue(":id_session", id_session);
        query.bindValue(":id_station", id_station);
        query.exec();

    }
    else
    {
        query.prepare("INSERT INTO signals (signal_dbm, signal,"
                       "field_strength_uv, link_budget, "
                       "terrain_attenuation, "
                       "clutter_attenuation, prop_mode,"
                       "id_session, id_station) VALUES (:signal_dbm,"
                      ":signal,:field_strength_uv,:link_budget,"
                      ":terrain_attenuation,:clutter_attenuation,"
                      ":prop_mode,:id_session,:id_station)");
        query.bindValue(":signal_dbm", s->signal_dbm);
        query.bindValue(":signal", s->signal);
        query.bindValue(":field_strength_uv", s->field_strength_uv);
        query.bindValue(":link_budget", s->link_budget);
        query.bindValue(":terrain_attenuation", s->terrain_attenuation);
        query.bindValue(":clutter_attenuation", s->clutter_attenuation);
        query.bindValue(":prop_mode", s->prop_mode);
        query.bindValue(":id_session", id_session);
        query.bindValue(":id_station", id_station);
        query.exec();

    }

}

void
DatabaseApi::update_replays(const unsigned &id_station, const unsigned &id_session,
                            const double &mobile_longitude, const double &mobile_latitude,
                            QString &id_replay, const Signal *s)
{
    QSqlQuery query(_db);
    query.prepare("INSERT INTO replays (mobile_longitude, mobile_latitude, "
                  "signal_dbm, signal,"
                   "field_strength_uv, link_budget, "
                   "terrain_attenuation, "
                   "clutter_attenuation, prop_mode,"
                   "id_session, id_station, id_replay) VALUES ("
                  ":mobile_longitude, :mobile_latitude, :signal_dbm,"
                  ":signal,:field_strength_uv,:link_budget,"
                  ":terrain_attenuation,:clutter_attenuation,"
                  ":prop_mode,:id_session,:id_station, :id_replay)");
    query.bindValue(":mobile_longitude", mobile_longitude);
    query.bindValue(":mobile_latitude", mobile_latitude);
    query.bindValue(":signal_dbm", s->signal_dbm);
    query.bindValue(":signal", s->signal);
    query.bindValue(":field_strength_uv", s->field_strength_uv);
    query.bindValue(":link_budget", s->link_budget);
    query.bindValue(":terrain_attenuation", s->terrain_attenuation);
    query.bindValue(":clutter_attenuation", s->clutter_attenuation);
    query.bindValue(":prop_mode", s->prop_mode);
    query.bindValue(":id_session", id_session);
    query.bindValue(":id_station", id_station);
    query.bindValue(":id_replay", id_replay);
    query.exec();
}


QVector<MobileStation *>
DatabaseApi::select_mobile_station(const unsigned &id_session)
{
    QVector<MobileStation *> mobile_stations;
    QSqlQuery query(_db);
    query.prepare("SELECT * FROM mobile_stations WHERE id_session=:id_session ORDER BY id ASC");
    query.bindValue(":id_session", id_session);
    query.exec();

    int id_idx = query.record().indexOf("id");
    int name_idx = query.record().indexOf("name");
    int id_session_idx = query.record().indexOf("id_session");
    int longitude_idx = query.record().indexOf("longitude");
    int latitude_idx = query.record().indexOf("latitude");
    int current_longitude_idx = query.record().indexOf("current_longitude");
    int current_latitude_idx = query.record().indexOf("current_latitude");
    int heading_deg_idx = query.record().indexOf("heading_deg");
    int elevation_feet_idx = query.record().indexOf("elevation_feet");
    int speed_idx = query.record().indexOf("speed");
    int frequency_idx = query.record().indexOf("frequency");
    int tx_power_watt_idx = query.record().indexOf("tx_power_watt");
    int terrain_following_idx = query.record().indexOf("terrain_following");
    int created_on_idx = query.record().indexOf("created_on");
    while(query.next())
    {
        MobileStation *mobile =new MobileStation;
        mobile->id = query.value(id_idx).toInt();
        mobile->id_session = query.value(id_session_idx).toInt();
        mobile->name = query.value(name_idx).toString();
        mobile->longitude = query.value(longitude_idx).toDouble();
        mobile->latitude = query.value(latitude_idx).toDouble();
        mobile->current_longitude = query.value(current_longitude_idx).toDouble();
        mobile->current_latitude = query.value(current_latitude_idx).toDouble();
        mobile->heading_deg = query.value(heading_deg_idx).toDouble();
        mobile->elevation_feet = query.value(elevation_feet_idx).toDouble();
        mobile->speed = query.value(speed_idx).toDouble();
        mobile->frequency = query.value(frequency_idx).toDouble();
        mobile->tx_power_watt = query.value(tx_power_watt_idx).toDouble();
        mobile->terrain_following = query.value(terrain_following_idx).toInt();
        mobile->created_on = query.value(created_on_idx).toInt();
        mobile_stations.push_back(mobile);
    }
    return mobile_stations;

}


QVector<GroundStation *>
DatabaseApi::select_ground_stations(const unsigned &id_session)
{
    QVector<GroundStation *> ground_stations;
    QSqlQuery query(_db);
    query.prepare("SELECT * FROM ground_stations WHERE id_session=:id_session ORDER BY id ASC");
    query.bindValue(":id_session", id_session);
    query.exec();
    int id_idx = query.record().indexOf("id");
    int name_idx = query.record().indexOf("name");
    int id_session_idx = query.record().indexOf("id_session");
    int longitude_idx = query.record().indexOf("longitude");
    int latitude_idx = query.record().indexOf("latitude");
    int heading_deg_idx = query.record().indexOf("heading_deg");
    int transmission_type_idx = query.record().indexOf("transmission_type");
    int elevation_feet_idx = query.record().indexOf("elevation_feet");
    int beacon_delay_idx = query.record().indexOf("beacon_delay");
    int frequency_idx = query.record().indexOf("frequency");
    int pitch_deg_idx = query.record().indexOf("pitch_deg");
    int polarization_idx = query.record().indexOf("polarization");
    int rx_antenna_height_idx = query.record().indexOf("rx_antenna_height");
    int rx_antenna_type_idx = query.record().indexOf("rx_antenna_type");
    int rx_antenna_gain_idx = query.record().indexOf("rx_antenna_gain");
    int rx_line_losses_idx = query.record().indexOf("rx_line_losses");
    int rx_sensitivity_idx = query.record().indexOf("rx_sensitivity");
    int tx_power_watt_idx = query.record().indexOf("tx_power_watt");
    int tx_antenna_height_idx = query.record().indexOf("tx_antenna_height");
    int tx_antenna_type_idx = query.record().indexOf("tx_antenna_type");
    int tx_antenna_gain_idx = query.record().indexOf("tx_antenna_gain");
    int tx_line_losses_idx = query.record().indexOf("tx_line_losses");
    int enabled_idx = query.record().indexOf("enabled");
    int created_on_idx = query.record().indexOf("created_on");
    while(query.next())
    {
        GroundStation *ground =new GroundStation;
        ground->id = query.value(id_idx).toInt();
        ground->id_session = query.value(id_session_idx).toInt();
        ground->name = query.value(name_idx).toString();
        ground->longitude = query.value(longitude_idx).toDouble();
        ground->latitude = query.value(latitude_idx).toDouble();
        ground->pitch_deg = query.value(pitch_deg_idx).toDouble();
        ground->heading_deg = query.value(heading_deg_idx).toDouble();
        ground->elevation_feet = query.value(elevation_feet_idx).toDouble();
        ground->transmission_type = query.value(transmission_type_idx).toInt();
        ground->beacon_delay = query.value(beacon_delay_idx).toInt();
        ground->frequency = query.value(frequency_idx).toDouble();
        ground->tx_power_watt = query.value(tx_power_watt_idx).toDouble();
        ground->polarization = query.value(polarization_idx).toInt();
        ground->rx_antenna_height = query.value(rx_antenna_height_idx).toDouble();
        ground->rx_antenna_gain = query.value(rx_antenna_gain_idx).toDouble();
        ground->rx_antenna_type = query.value(rx_antenna_type_idx).toString();
        ground->rx_line_losses = query.value(rx_line_losses_idx).toDouble();
        ground->rx_sensitivity = query.value(rx_sensitivity_idx).toDouble();
        ground->tx_antenna_height = query.value(tx_antenna_height_idx).toDouble();
        ground->tx_antenna_gain = query.value(tx_antenna_gain_idx).toDouble();
        ground->tx_antenna_type = query.value(tx_antenna_type_idx).toString();
        ground->tx_line_losses = query.value(tx_line_losses_idx).toDouble();
        ground->enabled = query.value(enabled_idx).toInt();

        ground->created_on = query.value(created_on_idx).toInt();
        ground_stations.push_back(ground);
    }

    return ground_stations;

}


QVector<FlightPlanPoints *>
DatabaseApi::select_flightplan_positions(const unsigned &id_session)
{
    QVector<FlightPlanPoints *> fp_points;
    QSqlQuery query(_db);
    query.prepare("SELECT * FROM flightplan_positions WHERE id_session=:id_session ORDER BY id ASC");
    query.bindValue(":id_session", id_session);
    query.exec();
    int id_idx = query.record().indexOf("id");
    int id_session_idx = query.record().indexOf("id_session");
    int longitude_idx = query.record().indexOf("longitude");
    int latitude_idx = query.record().indexOf("latitude");
    int altitude_idx = query.record().indexOf("altitude");
    int created_on_idx = query.record().indexOf("created_on");
    while(query.next())
    {
        FlightPlanPoints *fp = new FlightPlanPoints;
        fp->id = query.value(id_idx).toInt();
        fp->id_session = query.value(id_session_idx).toInt();
        fp->longitude = query.value(longitude_idx).toDouble();
        fp->latitude = query.value(latitude_idx).toDouble();
        fp->altitude = query.value(altitude_idx).toDouble();
        fp->created_on = query.value(created_on_idx).toInt();
        fp_points.push_back(fp);
    }

    return fp_points;

}


void
DatabaseApi::add_ground_station(const unsigned &id_session,
                                const double &lon, const double &lat,
                                const unsigned &time)
{
    QSqlQuery query(_db);
    query.prepare("INSERT INTO ground_stations ("
                  " id_session, longitude, "
                  "latitude, frequency, beacon_delay, transmission_type, elevation_feet, "
                  "polarization, rx_sensitivity, tx_power_watt, enabled, created_on) VALUES (:id_session, "
                  ":lon, :lat, :frequency, :beacon_delay, :transmission_type, :elevation_feet, "
                  ":polarization, :rx_sensitivity, :tx_power_watt, :enabled, :time)");
    query.bindValue(":id_session", id_session);
    query.bindValue(":lon", lon);
    query.bindValue(":lat", lat);
    query.bindValue(":frequency", 144.5);
    query.bindValue(":beacon_delay", 2);
    query.bindValue(":transmission_type", 1);
    query.bindValue(":elevation_feet", 0);
    query.bindValue(":polarization", 1);
    query.bindValue(":rx_sensitivity", -120.0);
    query.bindValue(":tx_power_watt", 1.0);
    query.bindValue(":enabled", 1);
    query.bindValue(":time", time);
    query.exec();

}

void
DatabaseApi::add_mobile_station(const unsigned &id_session,
                                const double &lon, const double &lat,
                                const unsigned &time)
{
    QSqlQuery query(_db);
    QSqlQuery query2(_db);
    query2.prepare("SELECT id FROM mobile_stations WHERE id_session=:id_session");
    query2.bindValue(":id_session", id_session);
    query2.exec();
    if(!query2.next())
    {
        query.prepare("INSERT INTO mobile_stations ("
                      " id_session, longitude, "
                      "latitude, terrain_following, created_on) VALUES (:id_session, "
                      ":lon, :lat, :terrain_following, :time)");
        query.bindValue(":id_session", id_session);
        query.bindValue(":lon", lon);
        query.bindValue(":lat", lat);
        query.bindValue(":terrain_following", 1);
        query.bindValue(":time", time);
        query.exec();
    }
    else
    {

        query.prepare("UPDATE mobile_stations SET "
                      " id_session=:id_session, longitude=:lon, "
                      "latitude=:lat, terrain_following=1, created_on=:time WHERE id=:id");
        query.bindValue(":id_session", id_session);
        query.bindValue(":lon", lon);
        query.bindValue(":lat", lat);
        query.bindValue(":terrain_following", 1);
        query.bindValue(":time", time);
        query.bindValue(":id", query2.value(0));
        query.exec();
        qDebug() << query.lastError().text();
    }


}

void
DatabaseApi::add_flightplan_position(const unsigned &id_session,
                                const double &lon, const double &lat,
                                const unsigned &time)
{
    QSqlQuery query(_db);
    query.prepare("INSERT INTO flightplan_positions ("
                  " id_session, longitude, "
                  "latitude, altitude, created_on) VALUES (:id_session, "
                  ":lon, :lat, :alt, :time)");
    query.bindValue(":id_session", id_session);
    query.bindValue(":lon", lon);
    query.bindValue(":lat", lat);
    query.bindValue(":alt", 0);
    query.bindValue(":time", time);
    query.exec();

}

void
DatabaseApi::delete_ground_station(const unsigned &id_session, const unsigned &id)
{
    QSqlQuery query(_db);
    query.prepare("DELETE FROM ground_stations WHERE "
                  " id_session=:id_session AND id=:id");
    query.bindValue(":id_session", id_session);
    query.bindValue(":id", id);
    query.exec();
}

void
DatabaseApi::delete_flightplan_position(const unsigned &id_session, const unsigned &id)
{
    QSqlQuery query(_db);
    query.prepare("DELETE FROM flightplan_positions WHERE "
                  " id_session=:id_session AND id=:id");
    query.bindValue(":id_session", id_session);
    query.bindValue(":id", id);
    query.exec();
}

void
DatabaseApi::update_ground_station(const unsigned &id_session, const unsigned &id,
                                   const QString &name, const double &frequency, const short &beacon_delay,
                                   const short &transmission_type, const double &elevation_feet,
                                   const double &heading_deg, const double &pitch_deg,
                                   const short &polarization, const double &tx_antenna_height,
                                   const QString &tx_antenna_type, const double &tx_antenna_gain,
                                   const double &tx_line_losses, const double &tx_power_watt,
                                   const double &rx_antenna_height, const QString &rx_antenna_type,
                                   const double &rx_antenna_gain, const double &rx_line_losses,
                                   const double &rx_sensitivity, const double &latitude, const double &longitude,
                                   const unsigned &time)
{
    QSqlQuery query(_db);
    query.prepare("UPDATE ground_stations SET id_session=:id_session,"
                  "name=:name, frequency=:frequency,"
                  "beacon_delay =:beacon_delay, transmission_type=:transmission_type,"
                  "elevation_feet =:elevation_feet, heading_deg=:heading_deg,"
                  "pitch_deg =:pitch_deg, polarization=:polarization,"
                  "tx_antenna_height =:tx_antenna_height, tx_antenna_type=:tx_antenna_type,"
                  "tx_antenna_gain =:tx_antenna_gain, tx_line_losses=:tx_line_losses,"
                  "tx_power_watt = :tx_power_watt, rx_antenna_height=:rx_antenna_height,"
                  "rx_antenna_type=:rx_antenna_type, rx_antenna_gain=:rx_antenna_gain,"
                  "rx_sensitivity=:rx_sensitivity, rx_line_losses=:rx_line_losses,"
                  "latitude=:latitude, longitude=:longitude,"
                  "created_on=:time WHERE id=:id");
    query.bindValue(":id_session", id_session);
    query.bindValue(":name", name);
    query.bindValue(":frequency", frequency);
    query.bindValue(":beacon_delay", beacon_delay);
    query.bindValue(":transmission_type", transmission_type);
    query.bindValue(":elevation_feet", elevation_feet);
    query.bindValue(":heading_deg", heading_deg);
    query.bindValue(":pitch_deg", pitch_deg);
    query.bindValue(":polarization", polarization);
    query.bindValue(":tx_antenna_height", tx_antenna_height);
    query.bindValue(":tx_antenna_type", tx_antenna_type);
    query.bindValue(":tx_antenna_gain", tx_antenna_gain);
    query.bindValue(":tx_line_losses", tx_line_losses);
    query.bindValue(":tx_power_watt", tx_power_watt);
    query.bindValue(":rx_antenna_height", rx_antenna_height);
    query.bindValue(":rx_antenna_type", rx_antenna_type);
    query.bindValue(":rx_antenna_gain", rx_antenna_gain);
    query.bindValue(":rx_sensitivity", rx_sensitivity);
    query.bindValue(":rx_line_losses", rx_line_losses);
    query.bindValue(":latitude", latitude);
    query.bindValue(":longitude", longitude);
    query.bindValue(":time", time);
    query.bindValue(":id", id);
    query.exec();


}


void
DatabaseApi::update_mobile_station(const unsigned &id_session, const unsigned &id,
                                   const QString &name, const double &frequency, const double &elevation_feet,
                                   const double &heading_deg, const double &tx_power_watt,
                                   const unsigned &terrain_following,
                                   const double &speed, const unsigned &time)
{
    QSqlQuery query(_db);
    QSqlQuery query2(_db);
    query2.prepare("SELECT id FROM mobile_stations WHERE id_session=:id_session");
    query2.bindValue(":id_session", id_session);
    query2.exec();
    if(query2.next())
    {
        query.prepare("UPDATE mobile_stations SET id_session=:id_session,"
                      "name=:name, frequency=:frequency,"
                      "elevation_feet =:elevation_feet, heading_deg=:heading_deg,"
                      "tx_power_watt = :tx_power_watt,"
                      "terrain_following=:terrain_following, speed=:speed,"
                      "created_on=:time WHERE id=:id");
        query.bindValue(":id_session", id_session);
        query.bindValue(":name", name);
        query.bindValue(":frequency", frequency);
        query.bindValue(":elevation_feet", elevation_feet);
        query.bindValue(":heading_deg", heading_deg);
        query.bindValue(":tx_power_watt", tx_power_watt);
        query.bindValue(":terrain_following", terrain_following);
        query.bindValue(":speed", speed);
        query.bindValue(":time", time);
        query.bindValue(":id", id);
        query.exec();

    }

}


void
DatabaseApi::update_mobile_position(const unsigned &id_session, const double &longitude, const double &latitude)
{
    QSqlQuery query(_db);
    query.prepare("UPDATE mobile_stations SET "
                  "current_longitude =:current_longitude, current_latitude=:current_latitude "
                  " WHERE id_session=:id_session");
    query.bindValue(":id_session", id_session);
    query.bindValue(":current_longitude", longitude);
    query.bindValue(":current_latitude", latitude);
    query.exec();

}


void
DatabaseApi::update_flightplan_position(const double &latitude, const double &longitude, const double &altitude, const unsigned &id_session, const unsigned &id)
{
    QSqlQuery query(_db);
    query.prepare("UPDATE flightplan_positions SET altitude=:altitude, latitude=:latitude, longitude=:longitude WHERE "
                  " id_session=:id_session AND id=:id");
    query.bindValue(":latitude", latitude);
    query.bindValue(":longitude", longitude);
    query.bindValue(":altitude", altitude);
    query.bindValue(":id_session", id_session);
    query.bindValue(":id", id);
    query.exec();
}
