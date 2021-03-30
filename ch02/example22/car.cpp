// clang-format off
/***************************************************************************
**
**  Copyright (C) 2021 by Sandro S. Andrade <sandroandrade@kde.org>
**
**  This file is part of the book "Cross-Platform Development with Qt 6".
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with Foobar. If not, see <https://www.gnu.org/licenses/>.
**
***************************************************************************/
// clang-format on

#include "car.h"

// NOLINTNEXTLINE(modernize-pass-by-value)
Car::Car(int id, const QString &brand, Engine engine,
         QObject *parent)
    : QObject{parent}
    , _id{id}
    , _brand{brand}
    , _engine{engine}
{
   int carId = 0;
   void *_a[] = {&carId};
   Car::qt_static_metacall(
       this,                       // pointer to target instance
       QMetaObject::ReadProperty,  // type of metacall
       0,                          // relative property index,
                                   // id is the first property in Car
       _a                          // array of return value and args
   );
   qDebug() << "My car's id:" << carId;
}

QString Car::brand() const { return _brand; }

void Car::setBrand(const QString &brand)
{
   if (_brand != brand) {
      _brand = brand;
      Q_EMIT brandChanged(_brand);
   }
}
