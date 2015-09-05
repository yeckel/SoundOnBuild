#include "makesoundonbuildplugin.h"
#include "makesoundonbuildconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>

#include <QtPlugin>
#include <QDebug>
#include <QSound>

using namespace MakeSoundOnBuild::Internal;

MakeSoundOnBuildPlugin::MakeSoundOnBuildPlugin()
{
    // Create your members
}

MakeSoundOnBuildPlugin::~MakeSoundOnBuildPlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

bool MakeSoundOnBuildPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    connect(Core::ProgressManager::instance(),SIGNAL(allTasksFinished(Core::Id)),this,SLOT(playSound(Core::Id)));
    return true;
}

void MakeSoundOnBuildPlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag MakeSoundOnBuildPlugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

void MakeSoundOnBuildPlugin::playSound(Core::Id id)
{
    if (id.toSetting().toString() == QStringLiteral("ProjectExplorer.Task.Build"))
        QSound::play(QStringLiteral(":/kids-cheer-01.wav"));
}

