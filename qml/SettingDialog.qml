import QtQuick 2.0
import QtQuick.Controls 2.12
//import QtGraphicalEffects 1.15
//import QtQuick.Controls.Styles 1.4

Dialog {
    id: dialog
    anchors.centerIn: parent
    width: 600
    height: 600


    background: Image {
        id:backgroundImage
        source: "/icons/Setting/33411769.jpg"
    }


    Rectangle {
        id: rectangle
        color: "transparent"
        anchors.bottomMargin: 555
        anchors.fill: parent

        Button {
            id: button
            width: 45
            height: 45
            anchors.left: parent.left
            anchors.leftMargin: 539
            background: Rectangle {

                color:  button.pressed ?  "#ccc" :"transparent"
            }

            Image {
                id: img1
                anchors.fill: parent
                source: "../icons/Setting/close.svg"
            }

            onClicked: dialog.close()
        }
    }

    Button {
        id: button1
        text: qsTr("Log Out")
        anchors.bottomMargin: 294
        anchors.leftMargin: 184
        anchors.rightMargin: 186
        anchors.topMargin: 238
        anchors.fill: parent

        onClicked:  Qt.quit()

    }

}

