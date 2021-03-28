###########################################################################
#
#   Copyright (C) 2021 by Sandro S. Andrade <sandroandrade@kde.org>
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

cmake_minimum_required(VERSION 3.14)

project(example21 LANGUAGES CXX)

set(CMAKE_AUTORCC ON)

if(NOT DEFINED QT_DEFAULT_MAJOR_VERSION)
   set(QT_DEFAULT_MAJOR_VERSION 6)
endif()

find_package(Qt${QT_DEFAULT_MAJOR_VERSION} COMPONENTS
   Widgets
   REQUIRED
)


add_executable(${PROJECT_NAME}
   main.cpp
   main.qrc
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)

target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Widgets)
