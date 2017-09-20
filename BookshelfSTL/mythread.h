#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QMutex>
#include <QThread>
#include <QWaitCondition>

//class Worker : public QThread
//{
//public:
//    Worker();

//    void registerCallback(ICallback *callback);
//    void unregisterCallback(ICallback *callback);

//protected:
//    virtual void run();

//private:
//    QMutex                    _mutex;
//    QWaitCondition            _wait;
//    bool                      _callingNow;
//    QLinkedList<ICallback *>  _callbacks;
//};

#endif // MYTHREAD_H
