import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Shapes 1.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property int radius: slider.value

    Slider {
        id: slider
        value: 50
        from: 0
        to: 150
    }

    Rectangle {
        color: 'yellow'
        anchors.centerIn: parent
        height: 180
        width: 320
    }
    Shape {
        id: shape
        anchors.centerIn: parent
        height: 180
        width: 320
        ShapePath {
            strokeColor: 'red'
            strokeWidth: 2
            fillColor: 'transparent'
            strokeStyle: ShapePath.DashLine
            dashPattern: [1, 2]

            startX: radius
            startY: 0
            PathLine {
                x: shape.width - radius
                y: 0
            }
            PathCubic {
                control1X: shape.width
                control2X: shape.width
                control1Y: 0
                control2Y: 0
                x: shape.width
                y: radius
            }
            PathLine {
                x: shape.width
                y: shape.height - radius
            }
            PathCubic {
                control1X: shape.width
                control2X: shape.width
                control1Y: shape.height
                control2Y: shape.height
                x: shape.width - radius
                y: shape.height
            }
            PathLine {
                x: radius
                y: shape.height
            }
            PathCubic {
                control1X: 0
                control2X: 0
                control1Y: shape.height
                control2Y: shape.height
                x: 0
                y: shape.height - radius
            }
            PathLine {
                x: 0
                y: radius
            }
            PathCubic {
                control1X: 0
                control2X: 0
                control1Y: 0
                control2Y: 0
                x: radius
                y: 0
            }
        }
    }
}
