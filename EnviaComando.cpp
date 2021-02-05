#include "EnviaComando.h"
#include <QtDBus/QDBusConnection>
#include <QtDBus/QtDBus>

EnviaComando::EnviaComando(QObject *parent) : QObject(parent)
{

}

void EnviaComando::sendCommand(const QString topic, const QString msg){

    if (!QDBusConnection::sessionBus().isConnected()) {
        qWarning("Não foi poss'ivel conectar ao QDBus\n");
        exit(0);
    }

    QDBusMessage DBusMsg = QDBusMessage::createSignal("/", SERVICE_NAME, "message");
    DBusMsg << msg;
    QDBusConnection::sessionBus().send(DBusMsg);

    qDebug() << "Topico: " << topic << ", Msg: " << msg;

}
