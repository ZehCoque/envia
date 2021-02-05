#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "CarregaArquivo.h"
#include "EnviaComando.h"
#include <QtDBus/QDBusConnection>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    qmlRegisterType<CarregaArquivo>("CarregaArquivo", 1, 0, "CarregaArquivo");
    qmlRegisterType<EnviaComando>("EnviaComando", 1, 0, "EnviaComando");

    return app.exec();
}
