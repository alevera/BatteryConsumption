/***************************************************************************
 *  	   Copyright (C) 2011  Nicola Parisi <nparisi89@gmail.com>	   *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

// Here we avoid loading the header multiple times
#ifndef WATTRATE_HEADER
#define WATTRATE_HEADER

#include <KIcon>
#include <Plasma/Applet>
#include <Plasma/Svg>
#include <QTimer>

#include "upower.h"
#include "upowerdevices.h"

class QSizeF;

// Define our plasma Applet
class WattRate : public Plasma::Applet
{
    Q_OBJECT
    public:
        // Basic Create/Destroy
        WattRate(QObject *parent, const QVariantList &args);
        ~WattRate();

        // The paintInterface procedure paints the applet to the desktop
        void paintInterface(QPainter *painter,
                const QStyleOptionGraphicsItem *option,
                const QRect& contentsRect);
        void init();

    private:
        Plasma::Svg m_svg;
        KIcon m_icon;
	double wattUsage;
	int incrementa;
	QString wattString;
	OrgFreedesktopUPowerInterface *upower;
	QList<OrgFreedesktopUPowerDeviceInterface*> *devices;

    private slots:
	    void updateWattUsage();
};
 
// This is the command that links your applet to the .desktop file
K_EXPORT_PLASMA_APPLET(wattrate, WattRate)
#endif
