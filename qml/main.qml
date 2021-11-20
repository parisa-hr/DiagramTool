import QtQuick 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    id: window
    visible: true
    visibility: "FullScreen"
    width: 700
    height:700
    title: qsTr("DiagramTool")

    background: Image {
        source: "/icons/base/galaxy_starfield.png"
    }


    LauncherPage {
        id: launcherPage
        focus: true
        anchors.fill: parent

    }

}
