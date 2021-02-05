#include "CarregaArquivo.h"
#include <QDebug>
#include <QFile>

CarregaArquivo::CarregaArquivo(QObject *parent) : QObject(parent)
{

}

QString CarregaArquivo::lerArquivo(QString filepath)
{
    QFile file(filepath.replace(0,7,"")); //edita a variavel filepath antes de chamar o QFile (retira os 7 chars iniciais)
    QString string; //iniciando a variável que guardará o conteúdo do arquivo

    if (!file.exists()) {
        return "Ocorreu um erro ao ler o arquivo! \nDescrição do erro:\n" + file.errorString(); //Retorna uma mensagem caso o arquivo nao for encontrado
    }

    if (file.open(QIODevice::ReadOnly | QFile::Text)){
        QTextStream in(&file);
        while (!in.atEnd()) { //enquanto nao se chega ao final do arquivo
            string += in.readLine(); //atribui a linha a variavel string
        }
    }

    file.close(); //fecha o arquivo
    return string; //retorna string

}
