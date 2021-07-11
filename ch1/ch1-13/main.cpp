/*
 * Foundations of Qt Development
 * Ch 1-13
 * Populating a QList and printing the contents
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
#include <QList>
#include <QString>
#include <QDebug>

int main() {
    QList<QString> list;
    list << "foo" << "bar" << "baz";
    foreach(const QString& s, list) {
        qDebug() << s;
    }
}
