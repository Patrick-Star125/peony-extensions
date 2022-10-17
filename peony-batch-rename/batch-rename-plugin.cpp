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
 * Authors: Meihong <hemeihong@kylinos.cn>
 *
 */

#include "batch-rename-plugin.h"
#include "rename-page.h"
#include <file-info.h>
#include <gio/gio.h>

#include <QAction>
#include <QFileInfo>
#include <QTranslator>
#include <QLocale>
#include <QApplication>
#include <QProcess>
#include <QUrl>
#include <QStandardPaths>
#include <QDebug>

using namespace Peony;

BatchRenamePlugin::BatchRenamePlugin(QObject *parent) : QObject (parent)
{
    QTranslator *t = new QTranslator(this);
    qDebug()<<"system().name:"<<QLocale::system().name();
    qDebug()<<"\n\n\n\n\n\n\ntranslate:"<<t->load(":/translations/peony-batch-rename_"+QLocale::system().name());
    QApplication::installTranslator(t);
}

QList<QAction*> BatchRenamePlugin::menuActions(Types types, const QString &uri, const QStringList &selectionUris)
{
    QList<QAction*> actions;
    //只有在文件窗口和桌面时可以调用右键菜单
    if (types == MenuPluginInterface::DirectoryView || types == MenuPluginInterface::DesktopWindow)
    {
        //只有选中了文件时可以进入右键菜单
        if (! selectionUris.isEmpty()) {
            QUrl url = selectionUris.first();
            //对于特殊的文件夹（home）不能进行全部重命名
            if (url.path() == QStandardPaths::writableLocation(QStandardPaths::HomeLocation)) {
                if (types == MenuPluginInterface::DesktopWindow) {
                    return actions;
                }
            }
            
            auto info = FileInfo::fromUri(selectionUris.first());
            //对于其它特殊的文件夹也不能进行全部重命名
            qDebug()<<"info isVirtual:"<<info->isVirtual()<<info->mimeType();
            if (selectionUris.first().startsWith("computer:///") ||
                selectionUris.first().startsWith("trash:///") ||
                selectionUris.first().startsWith("recent:///") ||
                selectionUris.first().startsWith("filesafe:///") ||
                info->isVirtual())
                  return actions;

            QFileInfo file(selectionUris.first());
            QAction *rename = new QAction(tr("batch rename"), nullptr);
            actions<<rename;
            connect(rename, &QAction::triggered, [=](){
                qDebug()<<"rename files:"<<uri<<selectionUris;
                QStringList::const_iterator constIterator;
                QStringList filesWithoutDir;
                std::vector<std::string> uploader;
                for (constIterator = selectionUris.constBegin(); constIterator != selectionUris.constEnd(); ++constIterator){
                    if (!constIterator.isDir()){
                        std::string tmp((*constIterator).toLocal8Bit().constData());
                        uploader.push_back(tmp);
                        filesWithoutDir.push_back((*constIterator));
                    }
                }
                RenamePage w;
                w.FileNamesInput(uploader);
                w.show();
                std::vector<std::string> receiver = w->file_names;
                std::string search = w->content_search;
                std::string replace = w->content_replace;
                char buf[512];
                snprintf(buf, 512, "s/%s/%s", search, replace);
                QProcess p;
                p.startDetached("rename", QStringList()<<buf<<filesWithoutDir);
                p.waitForFinished(-1);
            });
        }
    }
    return actions;
}
