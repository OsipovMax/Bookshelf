//#include "mythread.h"

//Worker::Worker() :
//    QThread(),
//    _mutex(QMutex::NonRecursive),
//    _callingNow(false)
//{
//    ...
//}

//void Worker::registerCallback(ICallback *callback)
//{
//    QMutexLocker locker(&_mutex);
//    _callbacks.append(callback);
//}

//void Worker::unregisterCallback(ICallback *callback)
//{
//    QMutexLocker locker(&_mutex);
//    _callbacks.removeOne(callback);
//    if(QThread::currentThread()!=this)
//    {
//        while(_callingNow)
//            _wait.wait(&_mutex);
//    }
//}

//void Worker::run()
//{
//    while(...)
//    {
//        QByteArray data;
//        ...
//        QLinkedList<ICallback *> callbacksCopy;

//        _mutex.lock();
//        _callingNow=true;
//        callbacksCopy=_callbacks;
//        _mutex.unlock();

//        for(QLinkedList<Callback *>::const_iterator it=callbacksCopy.begin();
//            it!=callbacksCopy.end();
//            ++it)
//        {
//            (*it)->dataReady(data);
//        }

//        _mutex.lock();
//        _callingNow=false;
//        _wait.wakeAll();
//        _mutex.unlock();
//    }
//}

