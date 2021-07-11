/*
 * Foundations of Qt Development
 * Ch 1-16
 * Appending, prepending, and inserting
 * Copyright (C) 2021  Arnab De <arkrde@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <QDebug>
#include <QList>
#include <QString>
#include <iostream>


int
main() {
    QList<QString> list;
    list << "first";
    list.append("second");
    list.prepend("third");
    list.insert(1, "fourth");
    list.insert(4, "fifth");
    
    size_t idx = 0;
    for(const auto& e: list) {
        std::cout << idx++ << ": " << e.toStdString() << '\n';
    }
    
}
