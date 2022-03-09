import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 1040
    height: 820
    visible: true
    title: qsTr("Interface")

    StackView {
        id:stackView
        anchors.fill: parent
        initialItem: Item

        TabBar {
            x: 10
            y: 20
            TabButton {
                text: qsTr("Serial")
                width: 70
                height: 30
                onClicked:
                {
                    stackView.push(Qt.resolvedUrl("qrc:/Serial.qml"))
                }
            }
        }
    }

}
