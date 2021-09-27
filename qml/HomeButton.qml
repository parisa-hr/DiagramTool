import QtQuick 2.12
import QtQuick.Controls 2.12

AbstractButton {
    id: button

    property int edge: Qt.TopEdge
    property alias imageSource: image.source

    contentItem: Image {
        id: image
        fillMode: Image.Pad
        sourceSize { width: 40; height: 40 } // ### TODO: resize the image
    }

    background: Rectangle {
        color: "white"
    }

    transform: Translate {
        Behavior on y { NumberAnimation { } }
        y: enabled ? 0 : edge === Qt.TopEdge ? -button.height : button.height
    }
}
