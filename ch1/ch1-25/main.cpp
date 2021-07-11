/*
 * Foundations of Qt Development
 * Ch 1-25
 * Populating a QSet; then showing the keys and testing for a specific key
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
#include <QSet>
#include <QString>

int
main() {
    QSet<QString> set;
    set << "Ada"
        << "C++"
        << "Ruby";
    for (QSet<QString>::ConstIterator b = set.begin(), e = set.end(); b != e;
         ++b) {
        qDebug() << *b;
    }
    if (set.contains("FORTRAN")) {
        qDebug() << "FORTRAN is in the set.";
    } else {
        qDebug() << "FORTRAN is not in the set.";
    }
}
