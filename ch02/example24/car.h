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

#ifndef CH02_EXAMPLE24_CAR_H_
#define CH02_EXAMPLE24_CAR_H_

#include <QObject>

class Car  // No QObject inheritance here
{
   Q_GADGET
   Q_PROPERTY(int id MEMBER _id CONSTANT)
   Q_PROPERTY(QString brand MEMBER _brand)

public:
   explicit Car(int id = 0, const QString &brand = {});
   Q_INVOKABLE void turnOn();

private:
   const int _id;
   QString _brand;
};

#endif  // CH02_EXAMPLE24_CAR_H_
