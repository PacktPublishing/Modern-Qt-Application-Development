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
#include <QIcon>
#include <QRegularExpression>
#include <QVBoxLayout>
#include <QWidget>

#include "myapplication.h"
#include "myevent.h"
#include "myeventfilter.h"
#include "mylabel.h"
#include "mylineedit.h"

int main(int argc, char **argv)
{
   // MyApplication reimplements notify() (approach 2)
   MyApplication app{argc, argv};
   QApplication::setWindowIcon(
       QIcon{QStringLiteral(":/icons/qtlogo.svg")});

   auto *topLevelWidget = new QWidget;
   // Installing an event filter on QApplication (approach 3)
   auto *myEventFilter = new MyEventFilter{topLevelWidget};
   app.installEventFilter(myEventFilter);

   topLevelWidget->setWindowTitle(QObject::tr("Layout Example"));
   auto *layout = new QVBoxLayout{topLevelWidget};

   // MyLabel reimplements a specific event handler (approach 1)
   layout->addWidget(
       new MyLabel{QObject::tr("Mouse enter/leave me!")});
   // MyLineEdit reimplements event() (approach 4)
   auto *myLineEdit
       = new MyLineEdit{QObject::tr("Key press me!")};
   layout->addWidget(myLineEdit);

   // Installing an event filter on target object (approach 5)
   myLineEdit->installEventFilter(myEventFilter);

   topLevelWidget->show();

   // Sending a custom event
   {
      MyEvent myEvent;
      qDebug() << "Sending custom event";
      QApplication::sendEvent(&app, &myEvent);
      qDebug() << "Custom event sent";
   }

   // Posting a custom event
   qDebug() << "Posting custom event";
   QApplication::postEvent(&app, new MyEvent);
   qDebug() << "Custom event posted";

   QObject::connect(&app, &QApplication::aboutToQuit,
                    [=]() { delete topLevelWidget; });

   return QApplication::exec();
}
