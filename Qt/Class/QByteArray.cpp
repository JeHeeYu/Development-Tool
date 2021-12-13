/*      Description     */
바이트(bit) 단위의 배열을 제공하는 클래수로, 배열을 핸들링 하기 위해 사용

/*      Header, qmake     */
#include <QByteArray>
QT += core

/*      Method     */

/* =============================== */

QByteArray.append() : 배열의 뒤에 데이터를 이어 붙이기 위한 함수

// Overloading
append(const QByteArray &ba);
append(char ch);
append(int count, char ch);
append(const char *str);
append(const char *str, int len);

// Argument
ch : 추가할 문자
*str : 추가할 문자열
len : 문자열의 길이로 자동 결정되며 str보다 길면 안됨
ba : 붙여넣을 데이터 보관
count : 바이트 배열에 문자 ch의 카운트 추가

// Example
QByteArray x("free");
QByteArray y("dom");
x.append(y);
// x == "freedom"

/* =============================== */

QByteArray.prepend() : 배열의 앞에 데이터를 이어 붙이기 위한 함수

// Overloading
prepend(const QByteArray &ba);
prepend(char ch);
prepend(int count, char ch);
prepend(const char *str);
prepend(const char *str, int len);

// Argument
ch : 추가할 문자
*str : 추가할 문자열
len : 문자열의 길이로 자동 결정되며 str보다 길면 안됨
ba : 붙여넣을 데이터 보관
count : 바이트 배열에 문자 ch의 카운트 추가

// Example
QByteArray x("ship");
QByteArray y("air");
x.prepend(y);
// x == "airship"
// x == "freedom"

/* =============================== */

QByteArray.replace() : 원하는 위치에 문자 또는 문자열을 변경하는 함수로 기존 문자열은 삭제

// Overloading
replace(int pos, int len, const QByteArray &after);
replace(int pos, int len, const char *after);
replace(int pos, int len, const char *after, int alen);
replace(char before, const char *after);
replace(char before, const QByteArray &after);
replace(const char *before, const char *after);
replace(const char *before, int bsize, const char *after, int asize);
replace(const QByteArray &before, const QByteArray &after);
replace(const QByteArray &before, const char *after);
replac(const char *before, const QByteArray &after);
replace(char before, char after);

// Argument
pos : 시작 위치로 배열 인덱스 번호
len : pos위치에서부터의 길이
&after : 뒤의 문자열을 변경할 문자열
*apfter : 뒤의 문자열을 변경할 문자열로, NULL로 끝나는 문자열로 변경할 수 있음
asize : *after의 사이즈
alen : pos와 같은 역할
before : 지정한 부분의 앞의 문자
&before : 앞의 문자열을 변경할 문자열
*before : 앞의 문자열을 변경할 문자열로, NULL로 끝나는 문자열로 변경할 수 있음
bsize : *before의 사이즈

// Example
QByteArray x("Say yes!");
QByteArray y("no");
x.replace(4, 3, y);
// x == "Say no!"

