/*
 * Foundations of Qt Development
 * Ch 1-26/27/28
 * Creating and populating a multimap
 * Finding the unique keys and iterating over each key and its associated items
 * Finding the item for a given key using an iterator
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
#include <QMultiMap>
#include <QSet>
#include <QString>

int
main() {
    QMultiMap<QString, int> multi;

    multi.insert("foo", 10);
    multi.insert("foo", 20);
    multi.insert("bar", 30);

    auto          keys = multi.keys();
    QSet<QString> keySet(keys.constBegin(), keys.constEnd());
    for (const auto &k : keySet) {
        qDebug() << "Key: " << k;
        for (const auto &v : multi.values(k)) {
            qDebug() << v;
        }
    }
    
    qDebug() << "Items for a specific key \'foo\'";
    QMultiMap<QString, int>::ConstIterator ii = multi.find("foo");
    while(ii != multi.end() && ii.key() == "foo") {
        qDebug() << ii.value();
        ++ii;
    }
}
