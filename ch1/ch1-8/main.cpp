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
