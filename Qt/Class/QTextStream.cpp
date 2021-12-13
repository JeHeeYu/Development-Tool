/*      Description     */
대량의 텍스트 또는 파일을 다루기 위한 Stream 처리 방식을 제공하는 클래스로,
QFile 클래스를 이용해 파일을 읽거나 쓸 수 있음

/*      Header, qmake     */
#include <QTextStream>
QT += core

/*      Constructor     */
QTextStream(const QByteArray &array, QIODevice::OpenMode openMode = QIODevice::ReadOnly);
QTextStream(QByteArray *array, QIODevice::OpenMode openMode = QIODevice::ReadWrite);
QTextStream(QString *string, QIODevice::OpenMode openMode = QIODevice::ReadWrite);
QTextStream(FILE *fileHandle, QIODevice::OpenMode openMode = QIODevice::ReadWrite);
QTextStream(QIODevice *device);
QTextStream();

/*      Method     */

// Overloading

// Arguments

// Example

/* =============================== */
