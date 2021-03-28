#!/bin/bash

#authorName=`git config user.name`
authorName="Sandro S. Andrade"
#authorEmail=`git config user.email`
authorEmail="sandroandrade@kde.org"
thisYear=`date +%Y`

find "$@" -name '*.h' -o -name '*.cpp' -o -name '*.qml' | grep -v /build | while read FILE; do
   if grep -qiE "Copyright \(C\) [0-9, -]{4,} by Sandro S. Andrade <sandroandrade@kde.org>" "$FILE"; then continue; fi
   thisfile=`basename $FILE`
   cat <<EOF > "$FILE".tmp
// clang-format off
/***************************************************************************
**
**  Copyright (C) $thisYear by $authorName <$authorEmail>
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

EOF
    cat "$FILE" >> "$FILE".tmp
    mv "$FILE".tmp "$FILE"
done

find "$@" -name 'CMakeLists.txt' | while read FILE; do
   if grep -qiE "Copyright \(C\) [0-9, -]{4,} by Sandro S. Andrade <sandroandrade@kde.org>" "$FILE"; then continue; fi
   cat <<EOF > "$FILE".tmp
###########################################################################
#
#   Copyright (C) $thisYear by $authorName <$authorEmail>
#
#   This file is part of the book "Cross-Platform Development with Qt 6".
#
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with Foobar. If not, see <https://www.gnu.org/licenses/>.
#
###########################################################################

EOF
    cat "$FILE" >> "$FILE".tmp
    mv "$FILE".tmp "$FILE"
done
