
/*
 * <one line to give the library's name and an idea of what it does.>
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

#ifndef CH_1_10_MYCLASS_H
#define CH_1_10_MYCLASS_H
#include <QDebug>
#include <QObject>
#include <QString>
/**
 * @todo write docs
 */
class MyClass : public QObject
{
  Q_OBJECT

public:
  MyClass(const QString &text, QObject *parent = nullptr)
      : QObject(parent), m_text(text) {}
  [[nodiscard]] const QString &text() const { return m_text; }
  [[nodiscard]] int getLengthOfText() const { return m_text.size(); }

public slots:
  void setText(const QString &text);

signals:
  void textChanged(const QString &);

private:
  QString m_text;
};

#endif // MYCLASS_H


