#include "EnviaComando.h"
#include <QtDBus/QDBusConnection>
#include <QtDBus/QtDBus>

EnviaComando::EnviaComando(QObject *parent) : QObject(parent)
{

}

void EnviaComando::sendCommand(const QString topic, const QString msg){

    if (!QDBusConnection::sessionBus().isConnected()) {
        qWarning("Não foi possivel conectar ao QDBus\n"); //erro retornado caso a conexao com o DBus nao tiver sido possivel
        exit(0);
    }

    QDBusMessage DBusMsg = QDBusMessage::createSignal("/", SERVICE_NAME, topic); //cria um sinal de mensagem DBus
    DBusMsg << msg; //atribui a variavel msg ao sinal DBus
    QDBusConnection::sessionBus().send(DBusMsg); //envia o sinal


}
