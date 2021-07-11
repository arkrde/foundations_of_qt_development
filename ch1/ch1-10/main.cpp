/*
 * Foundations of Qt Development
 * Ch-10
 * A class with a signal and a slot
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
#include <QtGui>
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include "myclass.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
    QApplication app(argc, argv);
    
    QWidget widget;
    QLineEdit* lineEdit = new QLineEdit;
    QLabel* label = new QLabel;
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(lineEdit);
    layout->addWidget(label);
    widget.setLayout(layout);
    
    MyClass* bridge = new MyClass("", &app);
    
    QObject::connect(lineEdit, 
                     SIGNAL(textChanged(const QString&)),
                     bridge,
                     SLOT(setText(const QString&))
             );
    QObject::connect(bridge,
                     SIGNAL(textChanged(const QString&)),
                     label,
                     SLOT(setText(const QString&))
             );
    
    widget.show();
    return app.exec();
}
