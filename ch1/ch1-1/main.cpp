// Foundations of Qt Development
// L1-3 : Dynamic memory without Qt
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
