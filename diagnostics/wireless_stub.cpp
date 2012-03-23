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

#include "wireless.h"

WirelessInterface::WirelessInterface(const QNetworkInterface &name)
{
    Q_UNUSED(name);
}

WirelessInterface::~WirelessInterface()
{
}

bool WirelessInterface::isValid() const
{
    return false;
}

QList<WirelessNetwork> WirelessInterface::availableNetworks()
{
    return QList<WirelessNetwork>();
}

WirelessNetwork WirelessInterface::currentNetwork()
{
    return WirelessNetwork();
}

WirelessStandards WirelessInterface::supportedStandards()
{
    return WirelessStandards();
}

