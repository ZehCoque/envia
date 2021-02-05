import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.0
import CarregaArquivo 1.0

Page {
    visible: true
    width: 640
    height: 480
    title: "Abrir Arquivo"
    Loader{
        id : openFileWindow
    }

    //Tornando o component TextArea scrollável
    ScrollView {
        width: parent.width - 50
        height: 300
        anchors.horizontalCenter: parent.horizontalCenter
        y: 30

        TextArea{
            id: textArea
            text: "O conteúdo do arquivo selecionado será mostrado aqui."
            wrapMode: "WordWrap"
            readOnly: true


        }

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

    CarregaArquivo{
        id: carregaArquivo
    }

    //FileDialog component
    FileDialog {
        id: fileDialog
//        folder: shortcuts.home
        //Talvez aqui seria interessante incluir a propriedade que permite selecionar apenas alguns formatos de arquivo. Contudo, isso nao foi especificado no projeto.
        onAccepted: {
            textArea.text = carregaArquivo.lerArquivo(this.fileUrl) // Envia nome de arquivo para o filestream

        }
    }

}
