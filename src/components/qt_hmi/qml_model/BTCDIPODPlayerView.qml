import QtQuick 2.0

Column {
    spacing: 25
    anchors.fill: parent
    property string playerType: ""
    Item{
        width: parent.width
        height: parent.height * 0.25
        Image{
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            source: "res/buttons/long_oval_btn.png"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    menuContainer.go("MusicSourceGridView.qml")
                }
            }
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                color: "#1d81d5"
                text: playerType
                font.pixelSize: 20
            }
        }

        Image{
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            source: "res/buttons/long_oval_btn.png"
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                color: "#1d81d5"
                text: "Browse"
                font.pixelSize: 20
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    //menuContainer.go(qml)
                }
            }
        }

    }
    Row{
        spacing: 50
        width: parent.width
        height: parent.height * 0.65
        x: 35
        Column{
            Image {
                id: albumArtImage
                source: "res/album_art.png"
            }
        }
        Column{
            spacing: 10
            Row{
                Text{
                    color: "#1d81d5"
                    text: "Track 13 / 16"
                    font.pixelSize: 20
                }
            }
            Row {
                Text{
                    color: "#1d81d5"
                    text: "Song name"
                    font.pixelSize: 45
                    font.bold: true
                }
            }
            Row {
                Text{
                    color: "#1d81d5"
                    text: "Album Name"
                    font.pixelSize: 25

                }
            }
        }
    }
    Row{
        width: parent.width
        height: parent.height / 4
        x: 35
        spacing: 10
        Text {
            id: songTimeText
            color: "white"
            text: "02:36"
            font.pixelSize: 18
        }
        Row{
            width: parent.width - 2 * (spacing + songTimeText.width) - x - 40
            Rectangle{
                y: songTimeText.height / 2 - 1
                width: parent.width / 5
                height: 2
                color: "white"
            }
            Rectangle{
                y: songTimeText.height / 2 - 1
                width: 4 * parent.width / 5
                height: 2
                color: "#1d81d5"
            }
        }
        Text {
            color: "#1d81d5"
            text: "04:23"
            font.pixelSize: 18
        }
    }
    Item{
        width: parent.width
        height: parent.height / 4
        Row{
            spacing: 25
            y: -70
            anchors.horizontalCenter: parent.horizontalCenter
            Image {
                id: prevBtnImage
                MouseArea {
                    anchors.fill: parent
                    onPressed: {
                        prevBtnImage.source = "res/buttons/player_prev_pressed_btn.png"
                    }
                    onReleased: {
                        prevBtnImage.source = "res/buttons/player_prev_btn.png"
                    }
                }
                source: "res/buttons/player_prev_btn.png"
                anchors.verticalCenter: parent.verticalCenter
            }
            Image {
                id: playBtnImage
                MouseArea {
                    anchors.fill: parent
                    onPressed: {
                        playBtnImage.source = "res/buttons/player_play_pressed_btn.png"
                    }
                    onReleased: {
                        playBtnImage.source = "res/buttons/player_play_btn.png"
                    }
                }
                source: "res/buttons/player_play_btn.png"
                anchors.verticalCenter: parent.verticalCenter
            }
            Image {
                id: nextBtnImage
                MouseArea {
                    anchors.fill: parent
                    onPressed: {
                        nextBtnImage.source = "res/buttons/player_next_pressed_btn.png"
                    }
                    onReleased: {
                        nextBtnImage.source = "res/buttons/player_next_btn.png"
                    }
                }
                source: "res/buttons/player_next_btn.png"
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

}
