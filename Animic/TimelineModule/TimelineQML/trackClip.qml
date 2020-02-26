import QtQuick 2.2
import QtQuick.Control 1.0

Rectangle{
	id: clipBase
	property string clipName: ''
    property int inPoint: 0
    property int outPoint: 0
    property int clipDuration: 0
    property bool isBlank: false
    property bool isAudio: false
    property bool selected: false
    property bool isTrackMute: false
    property int trackIndex
    property int originalTrackIndex: trackIndex
    property int originalClipIndex: index


	signal clicked(var clip, var mouse)
    signal moved(var clip)
    signal dragged(var clip, var mouse)
    signal dropped(var clip)
    signal draggedToTrack(var clip, int direction)
    signal trimmingIn(var clip, real delta, var mouse)
    signal trimmedIn(var clip)
    signal trimmingOut(var clip, real delta, var mouse)
    signal trimmedOut(var clip)

    SystemPalette { id: activePalette }
    gradient: Gradient {
        GradientStop {
            id: gradientStop
            position: 0.00
            color: Qt.lighter(getColor())
        }
        GradientStop {
            id: gradientStop2
            position: 1.0
            color: getColor()
        }
    }

    border.color: (selected || Drag.active || trackIndex != originalTrackIndex)? 'red' : 'black'
    border.width: isBlank? 0 : 1
    clip: true
    Drag.active: mouseArea.drag.active
    Drag.proposedAction: Qt.MoveAction
    opacity: Drag.active? 0.5 : 1.0

    MouseArea{
        //handle drag and drop
    }
}