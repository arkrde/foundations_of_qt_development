
// Foundations of Qt Development
// Listing 1-5 : MyClass using QString instead of std::string
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
