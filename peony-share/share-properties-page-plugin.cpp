/*
 * Peony-Qt's Library
 *
 * Copyright (C) 2019, Tianjin KYLIN Information Technology Co., Ltd.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Authors: Yue Lan <lanyue@kylinos.cn>
 * Authors: Meihong <hemeihong@kylinos.cn>
 *
 */

#include "share-properties-page-plugin.h"
#include "share-page.h"

#include <PeonyFileInfo>
#include <PeonyFileInfoJob>

#include <QLabel>
#include <QTranslator>
#include <QApplication>
#include <QFile>

#include <QDebug>

using namespace Peony;

SharePropertiesPagePlugin *global_instance = nullptr;

SharePropertiesPagePlugin *SharePropertiesPagePlugin::getInstance()
{
    return global_instance;
}

SharePropertiesPagePlugin::SharePropertiesPagePlugin(QObject *parent) : QObject(parent)
{
    qDebug()<<"init";
    QTranslator *t = new QTranslator(this);
    qDebug()<<"\n\n\n\n\n\n\n SharePropertiesPagePlugin translate:"<<t->load(":/translations/peony-share-extension_"+QLocale::system().name());
    QFile file(":/translations/peony-share-extension_"+QLocale::system().name()+".ts");
    qDebug()<<"file:"<<file.exists();
    QApplication::installTranslator(t);

    UserShareInfoManager::getInstance();

    global_instance = this;
}

bool SharePropertiesPagePlugin::supportUris(const QStringList &uris)
{
    if (uris.count() != 1) {
        return false;
    }
    //fix kylin security tool box-manager path can be shared issue
    if (uris.first().startsWith("file:///box"))
    {
        return false;
    }
    auto info = FileInfo::fromUri(uris.first());
    if (info->displayName().isNull()) {
        FileInfoJob j(info);
        j.querySync();
    }
    if (!info->isDir() || info->isVirtual() || !info->uri().startsWith("file:///")) {
        return false;
    }
    // don't share user's home directory file:///home/xxx/
    QStringList file = info->uri().split('/', QString::SkipEmptyParts);
    if ((3 == file.size ()) && (file.at(1) == "home")) {
        return false;
    }

    // don't share directory that has no permission
    if (!info->canRead() || !info->canWrite() || !info->canExecute()) {
        return false;
    }

    return true;
}

PropertiesWindowTabIface * SharePropertiesPagePlugin::createTabPage(const QStringList &uris)
{
    return new SharePage(uris.first());
}
