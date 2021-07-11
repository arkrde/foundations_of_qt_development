// Foundations of Qt Development
// Listing 1-4 : Dynamic memory with Qt
#include <QDebug>
#include <QObject>
#include <string>

using std::string;

class MyClass : public QObject {
public:
    MyClass(const string &text, QObject* parent = nullptr)
        : QObject(parent),
          m_text(text) {}
    string text() const { return m_text; }
    void setText(const string &text) { m_text = text; }
    int getLengthOfText() const { return m_text.size(); }

private:
    string m_text;
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
    QObject parent; /** allocated on stack and is automatically deleted **/
    MyClass *a, *b, *c;
    /** The following are allocated on the heap **/
    a = new MyClass("foo", &parent);
    b = new MyClass("ba-a-ar", &parent);
    c = new MyClass("baz", &parent);

    qDebug() << QString::fromStdString(a->text()) << " (" << a->getLengthOfText()
             << ")";

    a->setText(b->text());
    qDebug() << QString::fromStdString(a->text()) << " (" << a->getLengthOfText()
             << ")";

    return a->getLengthOfText() - c->getLengthOfText();
}
