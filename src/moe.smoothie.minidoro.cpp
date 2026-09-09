/*
 * This file is part of harbour-minidoro.
 * SPDX-FileCopyrightText: 2022 Mirian Margiani
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// #ifdef QT_QML_DEBUG
#include <QtQuick>
// #endif

#include <auroraapp.h>
#include "requires_defines.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(Aurora::Application::application(argc, argv));
    app->setOrganizationName("moe.smoothie");
    app->setApplicationName("minidoro");

    QScopedPointer<QQuickView> view(Aurora::Application::createView());

    view->engine()->addImportPath(Aurora::Application::pathTo("qml/modules").toString());

    view->rootContext()->setContextProperty("APP_VERSION", QString(APP_VERSION));
    view->rootContext()->setContextProperty("APP_RELEASE", QString(APP_RELEASE));

    view->setSource(Aurora::Application::pathToMainQml());
    view->show();
    
    return app->exec();
}
