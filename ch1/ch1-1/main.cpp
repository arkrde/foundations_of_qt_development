/*
 * Foundations of Qt Development
 * Ch 1-3
 * Dynamic memory without Qt
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
#include <iostream>
#include <cstdlib>

using std::string;

class MyClass {
    public:
        explicit MyClass(const string& text) : m_text(text) {};
        const string& text() const {return m_text;};
        void setText(const string& text) {m_text = text;};
        int getLengthOfText() const {return m_text.size();};

    private:
        string m_text;
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
    MyClass *a, *b, *c;
    a = new MyClass("foo");
    b = new MyClass("ba-a-ar");
    c = new MyClass("baz");

    std::cout << a->text() << "( " << a->getLengthOfText() <<" )" << std::endl;
    a->setText(b->text());
    std::cout << a->text() << "( " << a->getLengthOfText() <<" )" << std::endl;

    int result = a->getLengthOfText() - c->getLengthOfText();

    delete a;
    delete b;
    delete c;

    std::cout << "Result: " << result << std::endl;

    return EXIT_SUCCESS;

}
