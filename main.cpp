#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "libs/systemtime.h"
#include <QDateTime>
#include <QDebug>

int main(int argc, char *argv[])
{
//#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//#endif

//    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);
//    return app.exec();


    QDateTime currdate = QDateTime::currentDateTime();
    qDebug() << "Current date: "<< currdate;

    QDateTime prevdate = QDateTime::currentDateTime().addDays(-1);
    qDebug() << "Prev date: "<< prevdate;


    qDebug() << "Timezone: "<< currdate.timeZoneAbbreviation();

    SystemTime time;

    time.setNtp(true);
    qDebug() << "Ntp Status: "<< time.ntp();



    if(time.ntp()==true){
    time.setTime(QDateTime::currentDateTime());


//  time.setTimeZone("America/Chicago");

  time.setTimeZone("Europe/Istanbul");

  qDebug() << "Timezone changed to: "<< time.timeZone();

  QString a = time.time().toString();
  qDebug() << "System date changed via dbus: "<< a;
   }


}
