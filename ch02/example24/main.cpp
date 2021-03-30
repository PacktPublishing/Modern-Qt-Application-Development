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

   Car myCar{1};  // Creates a car with id=1
   const auto metaObject = Car::staticMetaObject;
   metaObject.property(metaObject.indexOfProperty("brand"))
       .writeOnGadget(&myCar, "QtCar");
   for (int i = 0; i < metaObject.propertyCount(); ++i) {
      auto metaProperty = metaObject.property(i);
      qDebug().nospace() << "\t" << metaProperty.name() << ": "
                         << metaProperty.readOnGadget(&myCar);
   }
   metaObject.method(metaObject.indexOfMethod("turnOn()"))
       .invokeOnGadget(&myCar);

   qRegisterMetaType<Car>();
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
   auto id = QMetaType::type("Car");
#else
   auto metaType = QMetaType::fromName("Car");
   auto id = metaType.id();
#endif
   if (id != QMetaType::UnknownType) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
      void *myCarPtr = QMetaType::create(id);
#else
      void *myCarPtr = metaType.create();
#endif
      metaObject.property(metaObject.indexOfProperty("brand"))
          .writeOnGadget(myCarPtr, "AmazingQtCar");
      qDebug() << metaObject
                      .property(
                          metaObject.indexOfProperty("brand"))
                      .readOnGadget(myCarPtr)
                      .toString();
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
      QMetaType::destroy(id, myCarPtr);
#else
      metaType.destroy(myCarPtr);
#endif
      myCarPtr = nullptr;
   }

   return 0;
}
