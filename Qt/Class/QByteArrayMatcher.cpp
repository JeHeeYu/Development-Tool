/*      Description     */
바이트(bit) 단위의 배열에서 매칭되는 바이트 배열 패턴을 찾기 위한 클래스

/*      Header, qmake     */
#include <QByteArrayMatcher>
QT += core

/*      Constructor     */
QByteArrayMatcher(const QByteArray &pattern);
QByteArrayMatcher(constchar *pattern, int length);
QByteArrayMatcher(const QByteArrayMatcher &other);

/*      Method     */
QByteArray.indexIn() : 배열에서 매칭되는 배열 패턴을 찾기 위한 함수

// Overloading
indexIn(const QByteArray &ba, int from = 0) const;
indexIn(const char *str, int len, int from = 0) const;

// Arguments
&ba : QByteArray 객체
*str : 찾을 문자열
len : from 위치부터의 사이즈
from : 바이트 위치 값으로 기본값은 0

// Example
QByteArray x("Hello Qt World!");
QByteArray y("Qt");
QByteArrayMatcher matcher(y);
int index = matcher.indexIn(x, 0);
// index == 6

/* =============================== */
