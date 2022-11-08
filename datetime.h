#ifndef DATETIME_H
#define DATETIME_H
#include "libs/systemtime.h"
#include <sys/time.h>

class DateTime: public QObject
{

public:
    DateTime();
    int getNtpStatus();
    int Timezone();



public slots:
    void setTimeZone(const QString &aTimeZone);
    void setDate(const QDateTime &adate);
    void setTime(const QTime &atime);
    void setNtp(const bool &_status);

 signals:
    void timeZoneChanged();
    void ntpChanged();
    void timeChanged();


};

#endif // DATETIME_H
