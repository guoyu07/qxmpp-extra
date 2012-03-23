/*
 * wiLink
 * Copyright (C) 2009-2010 Bolloré telecom
 * See AUTHORS file for a full list of contributors.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __DIAGNOSTICS_WIRELESS_H__
#define __DIAGNOSTICS_WIRELESS_H__

#include <QList>
#include <QString>
#include <QNetworkInterface>
#include <QXmlStreamWriter>

class QDomElement;

class WirelessNetwork
{
public:
    WirelessNetwork() : w_isCurrent(false), w_cinr(0), w_rssi(0) {};
    bool isValid() const { return !w_ssid.isEmpty(); };

    bool isCurrent() const { return w_isCurrent; };
    void setCurrent(bool isCurrent) { w_isCurrent = isCurrent; };

    int cinr() const { return w_cinr; };
    void setCinr(int cinr) { w_cinr = cinr; };

    int rssi() const { return w_rssi; };
    void setRssi(int rssi) { w_rssi = rssi; };

    QString ssid() const { return w_ssid; };
    void setSsid(const QString &ssid) { w_ssid = ssid; };

    void parse(const QDomElement &element);
    void toXml(QXmlStreamWriter *writer) const;

    bool operator==(const WirelessNetwork &other) const { return w_ssid == other.w_ssid; };
    bool operator!=(const WirelessNetwork &other) const { return w_ssid != other.w_ssid; };

private:
    bool w_isCurrent;
    int w_cinr;
    int w_rssi;
    QString w_ssid;
};

enum WirelessStandard
{
    Wireless_80211A = 1,
    Wireless_80211B = 2,
    Wireless_80211G = 4,
    Wireless_80211N = 8,
};

class WirelessStandards : public QFlags<WirelessStandard>
{
public:
    QString toString() const;
    static WirelessStandards fromString(const QString &str);
};

Q_DECLARE_OPERATORS_FOR_FLAGS(WirelessStandards)

class WirelessInterfacePrivate;

class WirelessInterface
{
public:
    WirelessInterface(const QNetworkInterface &networkInterface);
    ~WirelessInterface();

    WirelessNetwork currentNetwork();
    bool isValid() const;
    QList<WirelessNetwork> availableNetworks();
    WirelessStandards supportedStandards();

private:
    WirelessInterfacePrivate *d;
};

#endif
