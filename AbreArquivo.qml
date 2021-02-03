import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.0


Page {
    visible: true
    width: 640
    height: 480
    title: "Abrir Arquivo"
    Loader{
        id : openFileWindow
    }

    TextArea{
        //propriedades de texto
        id: textArea
        text: null
        wrapMode: "WordWrap"
        horizontalAlignment: TextEdit.AlignHCenter

        //propriedades de posição
        width: parent.width - 50
        height: 300
        anchors.horizontalCenter: parent.horizontalCenter
        y: 30

    }

    //Botão p/ chamar o QML FileDialog
    Button {
        id: selectFile
        text:"Selecionar Arquivo"
        anchors.horizontalCenter: parent.horizontalCenter
        y: parent.height - 120

        MouseArea{
            anchors.fill: parent
            onClicked: {
                //QML FileDialog
                fileDialog.open()

            }
        }

    }

    //FileDialog component
    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            textArea.text = this.fileUrl
        }
        onRejected: {
            console.log("Canceled")
        }

    }

}
