import QtQuick 2.0
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Item {
    property string settingText: "Setting"
    property string portNumberText: "Port Number"
    property string baudRateLabel: "Baud Rate"
    property string dataBitsLabel: "Data Bits"
    property string stopBitsLabel: "Stop Bits"
    property string parityBitsLabel: "Parity Bits"
    property string flowControlLabel: "Flow Control"

    Label {
        id: settingLabel
        x: 40
        y: 50
        text: settingText
        font.pointSize: 10
    }

    Rectangle {
        id: settingRectangle
        width: 400
        height: 500
        x: 30
        y: 70
        border.width: 0.5
        radius: 20

        Label {
            id: portnumberLabel
            x: 30
            y: 50
            text: portNumberText
            font.pointSize: 10
        }

        ComboBox {
            id:portNumberComboBOx
            x: 120
            y: 50
        }

    }





}

