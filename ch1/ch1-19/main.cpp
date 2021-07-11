/*
 * Foundations of Qt Development
 * Ch 1-19/20/21
 * Map
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
#include <QMap>
#include <QString>

int
main() {
    QMap<QString, int> map;
    map["foo"] = 42;
    map["bar"] = 13;
    map["baz"] = 9;
    qDebug() << "Using Qt foreach:";
    foreach (QString key, map.keys())
        qDebug() << "key: " << key << ", value: " << map[key];

    qDebug() << "Using Cpp range-based for:";
    for (const auto &key : map.keys())
        qDebug() << "key: " << key << ", value: " << map[key];

    qDebug() << "Using Cpp const iterators:";
    for (QMap<QString, int>::ConstIterator b = map.constBegin(),
                                           e = map.constEnd();
         b != e;
         ++b)
        qDebug() << "key: " << b.key() << ", value: " << b.value();

    qDebug() << "Accessing a key that does not exist using the [] operator:";
    int sum = map["foo"] + map["ingenting"];
    for (const auto &key : map.keys())
        qDebug() << "key: " << key << ", value: " << map[key];

    map.remove("ingenting");
    qDebug()
        << "Accessing a key that does not exist using the \'value\' method:";
    sum = map["foo"] + map.value("ingenting");
    for (const auto &key : map.keys())
        qDebug() << "key: " << key << ", value: " << map[key];
}
