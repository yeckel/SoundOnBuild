#ifndef MAKESOUNDONBUILD_H
#define MAKESOUNDONBUILD_H

#include "makesoundonbuild_global.h"

#include <extensionsystem/iplugin.h>
#include "coreplugin/id.h"
#include "coreplugin/progressmanager/progressmanager.h"

namespace MakeSoundOnBuild {
namespace Internal {

class MakeSoundOnBuildPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "MakeSoundOnBuild.json")

public:
    MakeSoundOnBuildPlugin();
    ~MakeSoundOnBuildPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private slots:
    void playSound(Core::Id id);
};

} // namespace Internal
} // namespace MakeSoundOnBuild

#endif // MAKESOUNDONBUILD_H

