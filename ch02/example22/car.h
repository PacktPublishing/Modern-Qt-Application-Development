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

#ifndef CH02_EXAMPLE22_CAR_H_
#define CH02_EXAMPLE22_CAR_H_

#include <QDebug>
#include <QObject>
#include <QVariant>

struct Engine {
   qreal horsepower;
   qint16 cylinders;
   bool operator!=(Engine other) {
      return horsepower != other.horsepower
             || cylinders != other.cylinders;
   }
   operator QVariant() const {
      return QVariant::fromValue(*this);
   }
   friend QDebug operator<<(QDebug dbg, Engine engine) {
      dbg << "Engine [ horsepower:" << engine.horsepower
          << ", cylinders:" << engine.cylinders << "]";
      return dbg;
   }
};

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
Q_DECLARE_METATYPE(Engine)  // No longer required in Qt 6
#endif

class Car : public QObject
{
   Q_OBJECT
   Q_PROPERTY(int id MEMBER _id CONSTANT)
   Q_PROPERTY(QString brand READ brand WRITE setBrand
                            NOTIFY brandChanged)
   Q_PROPERTY(Engine engine MEMBER _engine
                            NOTIFY engineChanged)
   Q_PROPERTY(Car::Type type MEMBER _type
                            NOTIFY typeChanged)

public:
   Car(int id, const QString &brand = {}, Engine engine = {},
       QObject *parent = nullptr);

   enum Type { HATCHBACK = 0, SUV, PICKUP };
   // cppcheck-suppress unknownMacro
   Q_ENUM(Type)

   QString brand() const;

public Q_SLOTS:
   void setBrand(const QString &brand);

Q_SIGNALS:
   void brandChanged(const QString &newBrand);
   void engineChanged(Engine newEngine);
   void typeChanged(Car::Type newType);

private:
   const int _id;
   QString _brand;
   Engine _engine;
   Type _type = HATCHBACK;
};

#endif  // CH02_EXAMPLE22_CAR_H_
