/*
 * Foundations of Qt Development
 * Ch 1-22/23/24
 * Hash
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
#ifndef CH_1_22_PERSON_H
#define CH_1_22_PERSON_H

#include <QHash>
#include <QString>

class Person {
  public:
    Person(const QString &name, const QString &number)
        : _name{name}
        , _number{number} {}
    const QString &name() const { return _name; };
    const QString &number() const { return _number; };

  private:
    QString _name, _number;
};

bool
operator==(const Person &p1, const Person &p2) {
    return (p1.name() == p2.name()) && (p1.number() == p2.number());
}

uint
qHash(const Person &key) {
    return qHash(key.name()) ^ qHash(key.number());
}

#endif // PERSON_H
