import QtQuick 2.11
import QtQuick.Controls 2.4


Item {
    id: element

    Rectangle
    {
        id:basePage
        anchors.fill: parent


        //        Image {
        //            id: name
        //            source:button.checked ? "/icons/base/gridPage.png" :""
        //        }


        FileOpen {
            id: fileOpen
            state: "collapsed"
            anchors {
                left: parent.left
                top: parent.top
                bottom: parent.bottom
                margins: scaledMargin
            }
            width: itemHeight + scaledMargin
            z: 2
            opacity: 0.9

            states: [
                State {
                    name: "expanded"
                    PropertyChanges {
                        target: fileOpen
                        width: itemWidth * 1.5
                        opacity: 0.8
                    }
                },
                State {
                    name: "collapsed"
                    PropertyChanges {
                        target: fileOpen
                        width: itemHeight + scaledMargin
                        opacity: 0.9
                    }
                }
            ]

            transitions: [
                Transition {
                    NumberAnimation { target: fileOpen; property: "width"; duration: 100 }
                    NumberAnimation { target: fileOpen; property: "opacity"; duration: 100 }
                }
            ]
        }
    }




    MouseArea {
        anchors.fill: parent
        onClicked: fileOpen.state == "expanded" ? fileOpen.state = "collapsed" : fileOpen.state = "expanded"
    }


    //        Button {
    //            id: button
    //            width: 117
    //            text: qsTr("page Grid")
    //            font.family: "Times New Roman"
    //            visible: true
    //            checkable: true
    //            focusPolicy: Qt.ClickFocus
    //            anchors.right: parent.right
    //            anchors.left: parent.left


    //        }
}

























/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:6;anchors_x:56;anchors_y:133}
}
 ##^##*/
