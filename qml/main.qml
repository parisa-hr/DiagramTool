import QtQuick 2.12
import QtQuick.Controls 2.4 as QQC2
import QtGraphicalEffects 1.0

//import ".."

QQC2.ApplicationWindow {
    id: window
    visible: true
    visibility: "FullScreen"
    width: 700
    height:700
    title: qsTr("DiagramTool")

    background: Image {
        source: "/icons/base/galaxy_starfield.png"
    }

//    background: Item {
//        id:backgroundcolor
//        anchors.fill: parent
//        //! set background color by useing gradinet
//        RadialGradient
//        {
//            anchors.fill: parent
//            gradient: Gradient {
//                GradientStop { position: 0.00 ; color: "#fffffff0" }
//                GradientStop { position: 0.30 ; color: "#ff000060" }
//                GradientStop { position: 0.35 ; color: "#ff000050" }
//                GradientStop { position: 0.40 ; color: "#ff000045" }
//                GradientStop { position: 0.45 ; color: "#ff000040" }
//                GradientStop { position: 0.50 ; color: "#ff000030" }
//                GradientStop { position: 0.60 ; color: "#ff000020" }
//                GradientStop { position: 1.00 ; color: "#ff000010" }
//            }
//        }
//    }



    QQC2.StackView {
        id: stackView

        focus: true
        anchors.fill: parent

        initialItem: LauncherPage {
            id: launcherPage

        }


    }

}
