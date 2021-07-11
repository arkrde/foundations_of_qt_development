/*
 * Foundations of Qt Development
 * Ch 1-8
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
#include "myclass.h"

int
main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
    QObject  parent;
    MyClass *a, *b, *c;

    a = new MyClass("foo", &parent);
    b = new MyClass("bar", &parent);
    c = new MyClass("baz", &parent);

    QObject::connect(a,
                     SIGNAL(textChanged(const QString &)),
                     b,
                     SLOT(setText(const QString &)));
    QObject::connect(b,
                     SIGNAL(textChanged(const QString &)),
                     c,
                     SLOT(setText(const QString &)));

    QObject::connect(c,
                     SIGNAL(textChanged(const QString &)),
                     b,
                     SLOT(setText(const QString &)));

    // Only a is modified but signal is not emitted from b
    qDebug() << "First run:";
    a->setText("bar");
    qDebug() << "a: " << a->text();
    qDebug() << "b: " << b->text();
    qDebug() << "c: " << c->text();

    // Both a and b is modified but signal is not emitted from c
    qDebug() << "Second run:";
    a->setText("baz");
    qDebug() << "a: " << a->text();
    qDebug() << "b: " << b->text();
    qDebug() << "c: " << c->text();

    // a, b, and c are all modified
    qDebug() << "Third run:";
    a->setText("test");
    qDebug() << "a: " << a->text();
    qDebug() << "b: " << b->text();
    qDebug() << "c: " << c->text();

    return 0;
}

#include "main.moc"
