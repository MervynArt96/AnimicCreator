import QtQuick 2.2
import QtQml.Models 2.1
import QtQuick.Controls 1.0
import "../TimelineQML" 1.0			

Rectangle{
	id: root
	property color animicBlue: dodgerblue
	width: 100
	height: 100

	MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.RightButton
        onClicked: menu.popup()
    }

	DropArea {
        anchors.fill: parent
        onEntered: {
            if (drag.formats.indexOf('application/vnd.mlt+xml') >= 0)
                drag.acceptProposedAction()
        }
        onExited: Logic.dropped()
        onPositionChanged: {
            if (drag.formats.indexOf('application/vnd.mlt+xml') >= 0)
                Logic.dragging(drag, drag.text)
        }
        onDropped: {
            if (drop.formats.indexOf('application/vnd.mlt+xml') >= 0) {
                if (currentTrack >= 0) {
                    Logic.acceptDrop(drop.getDataAsString('application/vnd.mlt+xml'))
                    drop.acceptProposedAction()
                }
            }
            Logic.dropped()
        }
    }

	Row{
		id: minimapRow
		

	}

	Row{
		id: trackRow



	}

	DelegateModel{
		id: timelineModel

	
	}

}
