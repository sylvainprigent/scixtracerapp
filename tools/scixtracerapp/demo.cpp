#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Inria");
    QCoreApplication::setApplicationName("SIMageViewer demo");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    QLabel label("Demo not yet impemented");
    label.show();

    app.setStyleSheet("file:///"+qApp->applicationDirPath()+QDir::separator()+"theme"+QDir::separator()+"stylesheet.css");
    return app.exec();
}
