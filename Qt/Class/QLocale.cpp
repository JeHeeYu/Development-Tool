/*      Description     */
숫자 및 문자를 다양한 언어로 변환하기 위한 클래스

/*      Header, qmake     */
#include <QLocale>
QT += core

/*      Constructor     */
QLoclae(const QLocale &other);
QLoclae(QLocale::Language language, QLocale::Script script, QLocale::Country country);
QLoclae(QLocale::Language language, QLocale::Country country = AnyCountry);
QLoclae(const QString &name);
QLoclae();

/*      Method     */

// Overloading

// Arguments

// Example

/* =============================== */
