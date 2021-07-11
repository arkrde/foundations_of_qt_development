/*
 * Foundations of Qt Development
 * Ch 1-17
 * Using a stack
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
#include <QStack>
#include <QString>


int
main() {
    QStack<QString> stack;
    
    stack.push("foo");
    stack.push("bar");
    stack.push("baz");
    
    QString result;
    result += "{" + stack.pop();
    while(!stack.isEmpty()) result += ", " + stack.pop();
    result += "}";

    qDebug() << "Output: " << result;
}
