/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2011  Radu Andries <admiral0@tuxfamily.org>
    Copyright (C) 2011  Nicola Parisi <nparisi89@gmail.com

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#ifndef UPOWERHANDLER_H
#define UPOWERHANDLER_H

#include <QtDBus>
#include <QList>
#include <QString>

struct Data {
  uint time; 
  double value;
  uint state;
};

typedef QList< Data > DataList;

Q_DECLARE_METATYPE(Data);
Q_DECLARE_METATYPE(DataList);

QDBusArgument &operator<<(QDBusArgument &argument, const Data &arg);
const QDBusArgument &operator>>(const QDBusArgument &argument, Data &t);

struct Stats {
  double value; 
  double accuracy;
};

typedef QList< Stats > StatsList;

Q_DECLARE_METATYPE(Stats);
Q_DECLARE_METATYPE(StatsList);

QDBusArgument &operator<<(QDBusArgument &argument, const Stats &arg);
const QDBusArgument &operator>>(const QDBusArgument &argument, Stats &t);

#endif // UPOWERHANDLER_H
