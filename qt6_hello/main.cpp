#include <QCoreApplication>
#include <iostream>
#include <string>

#include <QTextStream>
#include <QDebug>

void hello_cpp() {
    std::string name;
    std::cout << "Please enter your name:\n";
    std::getline(std::cin, name);
    std::cout << "Hello " << name << "\n\n";
}

void hello_qt() {
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    qout << "Please enter your name:\n";
    qout.flush();
    QString name = qin.readLine();
    qout << "Hello " << name << "\n\n";
    qout.flush();
}

void debug_qt() {
    // Spacing between << and auto line break
    qDebug() << "qDebug()" << "is used for writing custom debug output";
    qInfo() << "qInfo()" << "is used for informational messages";
    qWarning() << "qWarning()" << "is used to report warnings and recoverable errors in your application";
    qCritical() << "qCritical()" << "is used for writing critical error messages and reporting system errors";
    qFatal("qFatal() is used for writing fatal error messages shortly before exiting");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    hello_cpp();
    hello_qt();
    debug_qt();

    return a.exec();
}
