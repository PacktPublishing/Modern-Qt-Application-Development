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

#include <QApplication>
#include <QCheckBox>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QRegularExpression>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char **argv)
{
   QApplication app{argc, argv};
   QApplication::setWindowIcon(
       QIcon{QStringLiteral(":/icons/qtlogo.svg")});

   auto *topLevelWidget = new QWidget;
   topLevelWidget->setWindowTitle(QObject::tr("Layout Example"));
   auto *layout = new QVBoxLayout{topLevelWidget};
   layout->addWidget(new QLabel{QObject::tr("My Label")});
   layout->addWidget(new QLineEdit{QObject::tr("Change me!")});
   layout->addWidget(new QCheckBox{QObject::tr("Check me!")});
   topLevelWidget->show();

   layout->setObjectName(QStringLiteral("myLayout"));
   topLevelWidget->findChildren<QObject *>().at(1)->setObjectName(
       QStringLiteral("myLayout"));
   qDebug() << topLevelWidget->findChild<QLabel *>();
   qDebug() << topLevelWidget->findChild<QVBoxLayout *>(
       QStringLiteral("myLayout"));
   qDebug() << topLevelWidget->findChildren<QObject *>(
       QRegularExpression(QStringLiteral("^.*Layout$")));

   auto ret = QApplication::exec();

   delete topLevelWidget;

   return ret;
}
