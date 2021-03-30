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

#ifndef CH02_EXAMPLE23_MYLABEL_H_
#define CH02_EXAMPLE23_MYLABEL_H_

#include <QLabel>

class MyLabel : public QLabel
{
   Q_OBJECT

public:
   explicit MyLabel(const QString &text,
                    QWidget *parent = nullptr,
                    Qt::WindowFlags f = Qt::WindowFlags());

protected:
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
   virtual void enterEvent(QEvent *event);
#else
   void enterEvent(QEnterEvent *event) override;
#endif
   void leaveEvent(QEvent *event) override;
};

#endif  // CH02_EXAMPLE23_MYLABEL_H_
