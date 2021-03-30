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

#include "myeventfilter.h"

#include <QDebug>
#include <QEvent>

MyEventFilter::MyEventFilter(QObject *parent)
    : QObject(parent)
{
   // NOLINTNEXTLINE(google-build-using-namespace)
   using namespace std::chrono;  // NOLINT(build/namespaces)
   startTimer(5s);

   QTimer::singleShot(
       3s, this, []() { qDebug() << "Single-shot timer"; });
   connect(&_timer, &QTimer::timeout, this,
           []() { qDebug() << "Periodic timer"; });
   _timer.start(10s);
}

// cppcheck-suppress unusedFunction
bool MyEventFilter::eventFilter(QObject *watched,
                                QEvent *event)
{
   qDebug() << "MyEventFilter::eventFilter:" << event->type()
            << "event on" << watched;
   return false;
}

// cppcheck-suppress unusedFunction
void MyEventFilter::timerEvent(QTimerEvent *event)
{
   qDebug() << "MyEventFilter::timerEvent: timer ID ="
            << event->timerId();
}
