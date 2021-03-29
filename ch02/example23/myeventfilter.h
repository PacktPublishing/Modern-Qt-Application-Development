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

#ifndef CH02_EXAMPLE23_MYEVENTFILTER_H_
#define CH02_EXAMPLE23_MYEVENTFILTER_H_

#include <QObject>

class MyEventFilter : public QObject
{
   Q_OBJECT
public:
   explicit MyEventFilter(QObject *parent = nullptr);
   virtual bool eventFilter(QObject *watched, QEvent *event);
};

#endif  // CH02_EXAMPLE23_MYEVENTFILTER_H_
