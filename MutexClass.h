//
// Created by yaron on 18/12/2019.
//

#ifndef FLIGHTSIMULATOR_MUTEXCLASS_H
#define FLIGHTSIMULATOR_MUTEXCLASS_H
#include <sys/types.h>
#include <pthread.h>


 /* Current class is singletone class, created for purpose that other classes will have access to mutex */
class MutexClass {

    pthread_mutex_t mutex1;
    static MutexClass* instance;

    MutexClass() {
        mutex1 = PTHREAD_MUTEX_INITIALIZER;
    }

public:

     /* Method checks if already created instance of MutexClass. If it is, it returns
     pointer to this class. Else, it creates instance of class, and saves it as member */
    static MutexClass* getInstance();


    /* Method returns pointer to mutex*/
    pthread_mutex_t* getMutex();

};


#endif //FLIGHTSIMULATOR_MUTEXCLASS_H
