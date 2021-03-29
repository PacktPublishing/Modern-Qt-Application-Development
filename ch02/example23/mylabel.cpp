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

#include "mylabel.h"

#include <QDebug>
#include <QMouseEvent>

MyLabel::MyLabel(const QString &text, QWidget *parent,
                 Qt::WindowFlags f)
    : QLabel(text, parent, f)
{
}

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
void MyLabel::enterEvent(QEvent *event)
#else
void MyLabel::enterEvent(QEnterEvent *event)
#endif
{
   Q_UNUSED(event)
   qDebug() << "MyLabel::enterEvent";
   QLabel::enterEvent(event);
}

void MyLabel::leaveEvent(QEvent *event)
{
   Q_UNUSED(event)
   qDebug() << "MyLabel::leaveEvent";
   QLabel::leaveEvent(event);
}
