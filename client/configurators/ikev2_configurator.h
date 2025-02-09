#ifndef IKEV2_CONFIGURATOR_H
#define IKEV2_CONFIGURATOR_H

#include <QObject>
#include <QProcessEnvironment>

#include "core/defs.h"
#include "core/servercontroller.h"

class Ikev2Configurator
{
public:

    struct ConnectionData {
        QByteArray clientCert; // p12 client cert
        QByteArray caCert; // p12 server cert
        QString clientId;
        QString password; // certificate password
        QString host; // host ip
    };

    static QString genIkev2Config(const ServerCredentials &credentials, DockerContainer container,
        const QJsonObject &containerConfig, ErrorCode *errorCode = nullptr);

    static QString genIkev2Config(const ConnectionData &connData);
    static QString genMobileConfig(const ConnectionData &connData);
    static QString genStrongSwanConfig(const ConnectionData &connData);

    static ConnectionData prepareIkev2Config(const ServerCredentials &credentials,
        DockerContainer container, ErrorCode *errorCode = nullptr);
};

#endif // IKEV2_CONFIGURATOR_H
