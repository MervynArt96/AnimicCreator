import QtQuick 1.0
import QtQml.Models 2.1
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.11
import "../TimelineQML" 1.0			

Rectangle
{
	property color animicBlue: "dodgerblue"
    property int headerWidth: 150
    //property alias trackCount: tracksRepeater.count
    color: animicBlue
    
    width: 100
    height:100

    /*
	MouseArea
    {
        anchors.fill: parent
        acceptedButtons: Qt.RightButton
        onClicked: menu.popup()
    }

	DropArea
    {
        anchors.fill: parent
        onEntered:
        {
            if (drag.formats.indexOf('application/vnd.mlt+xml') >= 0)
                drag.acceptProposedAction()
        }
        onExited: Logic.dropped()
        onPositionChanged: 
        {
            if (drag.formats.indexOf('application/vnd.mlt+xml') >= 0)
                Logic.dragging(drag, drag.text)
        }
        onDropped: {
            if (drop.formats.indexOf('application/vnd.mlt+xml') >= 0) 
            {
                if (currentTrack >= 0)
                {
                    Logic.acceptDrop(drop.getDataAsString('application/vnd.mlt+xml'))
                    drop.acceptProposedAction()
                }
            }
            Logic.dropped()
        }
    }

	Row
    {
		id: minimapRow


		Rectangle
        {

        }

        Minimap
        {

        }

	}

	Row
    {
		id: trackRow
        Flickable
        {
            //contentY: ScrollView.flickableItem.contentY
            //width: headerWidth
            //height: trackHeaders.height
            //interactive: false
            Column
            {
                id: trackHeadList
                Repeater
                {
                    TrackHead
                    {

                    }
                }
            }

        }
	}


    Menu
    {
        id: menu

        MenuItem
        {
            text: qsTr('Test')
        }
    
    }

	DelegateModel
    {
		id: timelineModel

	
	}
    */
}
