/*
 * Foundations of Qt Development
 * Ch1-5
 * MyClass using QString
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
#include <QObject>
#include <QString>


class MyClass : public QObject {
public:
    MyClass(const QString &text, QObject* parent = nullptr)
        : QObject(parent),
          m_text(text) {}
    QString text() const { return m_text; }
    void setText(const QString &text) { m_text = text; }
    int getLengthOfText() const { return m_text.size(); }

private:
    QString m_text;
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
    QObject parent; /** allocated on stack and is automatically deleted **/
    MyClass *a, *b, *c;
    /** The following are allocated on the heap **/
    a = new MyClass("foo", &parent);
    b = new MyClass("ba-a-ar", &parent);
    c = new MyClass("baz", &parent);

    qDebug() << a->text() << " (" << a->getLengthOfText()
             << ")";

    a->setText(b->text());
    qDebug() << a->text() << " (" << a->getLengthOfText()
             << ")";

    return a->getLengthOfText() - c->getLengthOfText();
}
