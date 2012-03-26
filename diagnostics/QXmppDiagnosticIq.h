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

#ifndef __DIAGNOSTICS_IQ_H__
#define __DIAGNOSTICS_IQ_H__

#include <QHostInfo>

#include "QXmppIq.h"

#include "interface.h"
#include "network.h"
#include "software.h"
#include "transfer.h"
#include "wireless.h"

extern const char* ns_diagnostics;

class DiagnosticsIq : public QXmppIq
{
public:
    QList<Interface> interfaces() const;
    void setInterfaces(QList<Interface> &interfaces);

    QList<QHostInfo> lookups() const;
    void setLookups(const QList<QHostInfo> &lookups);

    QList<QHostAddress> nameServers() const;
    void setNameServers(const QList<QHostAddress> &nameServers);

    QList<Ping> pings() const;
    void setPings(const QList<Ping> &pings);

    QList<Software> softwares() const;
    void setSoftwares(const QList<Software> &softwares);

    QList<Traceroute> traceroutes() const;
    void setTraceroutes(const QList<Traceroute> &traceroutes);

    QList<Transfer> transfers() const;
    void setTransfers(const QList<Transfer> &transfer);

    static bool isDiagnosticsIq(const QDomElement &element);

protected:
    void parseElementFromChild(const QDomElement &element);
    void toXmlElementFromChild(QXmlStreamWriter *writer) const;

private:
    QList<Interface> m_interfaces;
    QList<QHostInfo> m_lookups;
    QList<QHostAddress> m_nameServers;
    QList<Ping> m_pings;
    QList<Software> m_softwares;
    QList<Traceroute> m_traceroutes;
    QList<Transfer> m_transfers;
};

#endif
