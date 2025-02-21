import QtQuick 2.12
import QtQuick.Controls 2.12
import "."

BasicButtonType {
    id: root
    icon.color: "#181922"

    background: Item {}
    contentItem: SvgImageType {
        svg.source: icon.source
        color: icon.color
        anchors.fill: parent
        anchors.margins: parent.containsMouse ? 0 : 1
    }
}
