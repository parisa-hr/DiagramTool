import QtQuick 2.12
import QtQuick.Controls 2.12


Item {
    id: item
    visible: true
    anchors.fill: parent
    signal showUseCase()
    signal showClass()
    signal showSequence()
    signal showComponent()
    signal showActivity()
    signal showDeployment()
    signal showSettings()

    Image {
        anchors.fill: parent
        source: "/icons/base/galaxy_starfield.png"
    }


    PathView {
        id: circularView
        anchors.fill:parent
        focus: true


        readonly property int cX: width / 2
        readonly property int cY: height / 2
        readonly property int itemSize: size / 4
        readonly property int size: Math.min(width - 80, height)
        readonly property int radius: size / 2 - itemSize / 3



        snapMode: PathView.SnapToItem

        model: ListModel {
            ListElement {
                title: qsTr("UseCase Diagram")
                icon:"UseCase"


            }
            ListElement {
                title: qsTr("Class Diagram")
                icon: "Class"
                page: "Diagrams/UseCase.qml"
            }
            ListElement {
                title: qsTr("Sequence Diagram")
                icon: "Sequence"
            }
            ListElement {
                title: qsTr("Component Diagram")
                icon: "Component"
            }
            ListElement {
                title: qsTr("Activity Diagram")
                icon: "Activity"
            }
            ListElement {
                title: qsTr("Deployment Diagram")
                icon: "Deployment"
                page: "Alarms/AlarmsPage.qml"
            }
            ListElement {
                title: qsTr("Settings")
                icon: "setting"
            }
        }

        delegate: RoundButton {
            width: circularView.itemSize
            height: circularView.itemSize

            property string title: model.title

            icon.width: 120
            icon.height: 120
            icon.name: model.icon
            icon.color: "transparent"
            opacity: PathView.itemOpacity
            padding: 8

            background: Rectangle {
                radius: width / 2
                border.width: 3
                border.color: parent.PathView.isCurrentItem ? "#D32D0A" : "#108490"
            }

            onClicked: {

                if (PathView.isCurrentItem)
                    if(circularView.currentIndex==0)
                        item.showUseCase()
                    else if(circularView.currentIndex==1)
                        item.showClass()
                    else if(circularView.currentIndex==2)
                        item.showSequence()
                    else if(circularView.currentIndex==3)
                        item.showComponent()
                    else if(circularView.currentIndex==4)
                        item.showActivity()
                    else if(circularView.currentIndex==5)
                        item.showDeployment()
                    else
                        item.showSettings()

                else
                    circularView.currentIndex = index
            }
        }

        path: Path {
            startX: circularView.cX
            startY: circularView.cY
            PathAttribute {
                name: "itemOpacity"
                value: 1.0
            }
            PathLine {
                x: circularView.cX + circularView.radius
                y: circularView.cY
            }
            PathAttribute {
                name: "itemOpacity"
                value: 0.7
            }
            PathArc {
                x: circularView.cX - circularView.radius
                y: circularView.cY
                radiusX: circularView.radius
                radiusY: circularView.radius
                useLargeArc: true
                direction: PathArc.Clockwise
            }
            PathAttribute {
                name: "itemOpacity"
                value: 0.5
            }
            PathArc {
                x: circularView.cX + circularView.radius
                y: circularView.cY
                radiusX: circularView.radius
                radiusY: circularView.radius
                useLargeArc: true
                direction: PathArc.Clockwise
            }
            PathAttribute {
                name: "itemOpacity"
                value: 0.3
            }
        }

        Text {
            id: appTitle

            property Item currentItem: circularView.currentItem

            visible: currentItem ? currentItem.PathView.itemOpacity === 1.0 : 0

            text: currentItem ? currentItem.title : ""
            font.family: "Times New Roman"
            anchors.centerIn: parent
            anchors.verticalCenterOffset: (circularView.itemSize + height) / 2

            font.bold: true
            styleColor: "#F7F95B"
            horizontalAlignment: Text.AlignHCenter
            style: Text.Outline
            font.pointSize: 3
            font.pixelSize: circularView.itemSize / 5
            font.letterSpacing: 1

        }
    }
}
