import QtQuick 2.0
import QtQuick.Controls 2.15

Page {
    visible: true
    width: 640
    height: 480
    title: qsTr("Menu Principal")
    Loader{
        id : mainWindow
    }

    TextArea{
        //propriedades de texto
        text: "Bem vindo à primeira atividade do desafio da vaga de Desenvolvedor de Software da Otmis - Jacto."
        wrapMode: "WordWrap"
        horizontalAlignment: TextEdit.AlignHCenter

        //propriedades de posição
        width: parent.width - 50
        anchors.horizontalCenter: parent.horizontalCenter
        y: 30

    }

    TextArea{
        text: "Desenvolvido por José Antonio Rico Coque"
        anchors.horizontalCenter: parent.horizontalCenter
        y: 90
    }

    Row {
        anchors{
            horizontalCenter: parent.horizontalCenter
        }
        y: parent.height - 120
        spacing: 60

        //Botão AbreArquivo
        Button {
            id: openFileButton
            text: "Abrir Arquivo"

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    stackView.push("AbreArquivo.qml")
                }
            }
        }

        //Botão TransmiteComando
        Button {
            id: sendCommandButton
            text:"Enviar Comando"

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    stackView.push("TransmiteComando.qml")
                }
            }
        }

        //Botão para fechar app
        Button {
            id: exitButton
            text: "Sair/Encerrar"

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    Qt.quit()
                }
            }
        }


    }

}
