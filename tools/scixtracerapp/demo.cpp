#include <scixtracerapp>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Inria");
    QCoreApplication::setApplicationName("SciXtracer app demo");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    SxExperimentComponent experimentComponent;
    experimentComponent.getWidget()->show();

    app.setStyleSheet("file:///"+qApp->applicationDirPath()+QDir::separator()+"theme"+QDir::separator()+"default"+QDir::separator()+"stylesheet.css");
    return app.exec();
}
