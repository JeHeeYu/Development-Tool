/*      Description     */
문자 및 문자열 생성 클래스

/*      Header, qmake     */
#include <QString>
QT += core

/*      Constructor     */
QString(const QByteArray &ba);
QString(const char *str);
QString(QString &&other);
QString(const QString &other);
QString(QLatin1String str);
QString(int size, QChar ch);
QString(QChar ch);
QString(const QChar *unicode, int size= -1);
QString();

/*      Method     */


// Overloading


// Arguments


// Example
QString str = "Hello";
// str == "Hello"

/* =============================== */
