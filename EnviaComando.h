#ifndef ENVIACOMANDO_H
#define ENVIACOMANDO_H

#include <QObject>

#define SERVICE_NAME            "org.example.QtDBus.PingExample"

class EnviaComando : public QObject
{
    Q_OBJECT
public:
    explicit EnviaComando(QObject *parent = nullptr);
    Q_INVOKABLE void sendCommand(const QString topic, const QString msg);

signals:

};

#endif // ENVIACOMANDO_H
