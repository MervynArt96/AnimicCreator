import QtQuick 2.2
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 2.0
import QtQuick.Layouts 2.0

Rectangle{
	id: rulerRoot
	property real timeScale: 1.0
    property int adjustment: 0
    property real intervalSeconds: 5 * Math.max(1, Math.floor(1.5 / timeScale)) + adjustment

    SystemPalette { id: activePalette }

    id: rulerTop
    enabled: false
    height: 28
    color: activePalette.base

	Repeater{
		model: parent.width / (intervalSeconds * profile.fps * timeScale)
        Rectangle{
            
        }


	}
    
    Connections {
        target: profile
        onProfileChanged: {
            // Force a repeater model change to update the labels.
            ++adjustment
            --adjustment
        }
    }
}