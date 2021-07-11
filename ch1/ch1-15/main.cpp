/*
 * Foundations of Qt Development
 * Ch 1-15
 * Modifying lists using iterators
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

typedef QMutableListIterator<int> IntListJavaIterator;
typedef QList<int>::iterator      IntListSTLIterator;

int
main() {
    QList<int> list;
    list << 23 << 33 << 61 << 62;

    IntListJavaIterator javaIter(list);
    while (javaIter.hasNext()) {
        javaIter.setValue(javaIter.next() + 1);
    }

    qDebug() << "Java iterator:";
    javaIter.toFront();
    while (javaIter.hasNext()) {
        qDebug() << javaIter.next();
    }

    qDebug() << "C++ STL iterator:";
    IntListSTLIterator b, e;
    for (b = list.begin(), e = list.end(); b != e; ++b) {
        *b *= 2;
        qDebug() << *b;
    }

    qDebug() << "C++ range-based for loop:";
    for (auto &e : list) {
        e *= 2;
        qDebug() << e;
    }
    
    qDebug() << "Accessing specific elements:";
    qDebug() << "2nd element: " << list[2];
}
