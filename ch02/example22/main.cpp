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

#include <QDebug>
#include <QMetaProperty>

#include "car.h"

int main(int argc, char **argv)
{
   Q_UNUSED(argc)
   Q_UNUSED(argv)

   Car myCar{1};

   // Handling properties using accessors and mutators
   myCar.setObjectName(QStringLiteral("My car"));
   myCar.setBrand(QStringLiteral("QtCar"));
   qDebug() << "My car's brand:" << myCar.brand() << Qt::endl;

   // Handling properties using Qt's property system
   myCar.setProperty("id", 2);
   myCar.setProperty("brand", QStringLiteral("AmazingQtCar"));
   myCar.setProperty("engine", Engine{120, 6});
   myCar.setProperty("type", Car::SUV);
   qDebug() << "My car's id:" << myCar.property("id").toInt();
   qDebug() << "My car's brand:"
            << myCar.property("brand").toString();
   qDebug() << "My car's engine:"
            << myCar.property("engine").value<Engine>();
   qDebug() << "My car's type:"
            << myCar.property("type").value<Car::Type>()
            << Qt::endl;

   // Creating a dynamic property
   myCar.setProperty("currentSpeed", 51.7);

   // Showing all static properties
   qDebug() << "MyCar's static properties:";
   auto *metaObject = myCar.metaObject();
   for (int i = 0; i < metaObject->propertyCount(); ++i) {
      auto metaProperty = metaObject->property(i);
      qDebug() << "\t" << metaProperty.name() << ":"
               << metaProperty.read(&myCar);
   }

   // Showing all dynamic properties
   qDebug() << Qt::endl << "MyCar's dynamic properties:";
   for (const auto &propertyName : myCar.dynamicPropertyNames()) {
      qDebug() << "\t" << propertyName << ":"
               << myCar.property(propertyName);
   }

   // Removing a dynamic property
   myCar.setProperty("currentSpeed", {});
}
