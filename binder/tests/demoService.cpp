#include <iostream>

#include <sys/types.h>
#include <unistd.h>

#include <binder/IPCThreadState.h>
#include <binder/BinderService.h>
#include "IDemoService.h"

using namespace std;
using namespace android;

namespace my_test
{

class BnDemoImpl : public BnInterface<IDemoInterface>
{
public:
    uint64_t getEuid() const;
    uint64_t getPid() const;

protected:
    status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
//private:
public:
//    friend class DemoServiceStarter;
    static char const * getServiceName() { return "demoService"; };
};

class DemoServiceStarter : BinderService<BnDemoImpl>
{
};

uint64_t BnDemoImpl::getEuid() const
{
    return geteuid();
};

uint64_t BnDemoImpl::getPid() const
{
    return getpid();
};

status_t BnDemoImpl::onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags)
{
    pid_t pid = IPCThreadState::self()->getCallingPid();
    uid_t uid = IPCThreadState::self()->getCallingUid();
    cout << "called from pid: " << pid << ", uid: " << uid << ", code: " << code << endl;

    switch(code) {
    case DEMO_GET_PID:
        reply->writeUint64(pid);
        return OK;
        break;

    case DEMO_GET_UID:
        reply->writeUint64(uid);
        return OK;
        break;

    case DEMO_LIST_SERVICES:
    default:
        break;
    }
    return BBinder::onTransact(code, data, reply, flags);
};


}; // end of namespace my_test


using namespace my_test;

int main(int argc, char * argv[])
{
    cout << "Starting Demo service...";
    DemoServiceStarter::publishAndJoinThreadPool();
    cout << " started\n";

    while(true){
        sleep(5);
    }
}

