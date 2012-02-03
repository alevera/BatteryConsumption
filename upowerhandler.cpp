/*
    Copyright (C) 2011  Radu Andries <admiral0@tuxfamily.org>
    Copyright (C) 2011  Nicola Parisi <nparisi89@gmail.com>

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


#include "upowerhandler.h"

QDBusArgument &operator<<(QDBusArgument &argument, const Data &arg){
  argument.beginStructure();
  argument << arg.time << arg.value << arg.state;
  argument.endStructure();
  return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, Data &t){
  argument.beginStructure();
  argument >> t.time >> t.value >> t.state;
  argument.endStructure();
  return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument, const Stats &arg){
  argument.beginStructure();
  argument << arg.value << arg.accuracy ;
  argument.endStructure();
  return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument, Stats &t){
  argument.beginStructure();
  argument >> t.value >> t.accuracy ;
  argument.endStructure();
  return argument;
}