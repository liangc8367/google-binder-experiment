#include <iostream>

#include <sys/types.h>
#include <unistd.h>

#include <binder/IPCThreadState.h>
#include <binder/BinderService.h>
#include "IDemoInterface.h"

using namespace std;
using namespace android;

namespace my_test
{

class BnDemoImpl : public BnInterface<IDemoInterface>
{
public:
    uint64_t getEuid() const;
    uint64_t getPid() const;
    vector<String16> listServices();

protected:
    status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
private:
    friend class BinderService<BnDemoImpl>;
    static char const * getServiceName() { return MY_IFACE_NAME; };
};

uint64_t BnDemoImpl::getEuid() const
{
    return geteuid();
};

uint64_t BnDemoImpl::getPid() const
{
    return getpid();
};

vector<String16> BnDemoImpl::listServices()
{
    sp<IServiceManager> svcMgr = defaultServiceManager();
    Vector<String16> services = svcMgr->listServices();

    vector<String16> svcs;

    cout << "services are: " << endl;
    for(size_t i = 0; i < services.size(); i++){
        cout << services[i] << endl;
        svcs.push_back(String16(services[i]));
    }
    cout << "." << endl;
    return svcs;
}

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
    {
        vector<String16> services = listServices();
        reply->writeString16Vector(services);
        return OK;
    }
        break;

    default:
        return BBinder::onTransact(code, data, reply, flags);
        break;
    }
};

}; // end of namespace my_test


using namespace my_test;

int main(int argc, char * argv[])
{
    cout << "Starting Demo service...";
    BinderService<BnDemoImpl>::publishAndJoinThreadPool();
    cout << " started\n";

    while(true){
        sleep(5);
    }
}

