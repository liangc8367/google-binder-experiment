#include <binder/Parcel.h>
#include "IDemoInterface.h"

using namespace android;
using namespace my_test;

class BpDemoInterface : public BpInterface<IDemoInterface>
{
public:
    BpDemoInterface(const sp<IBinder> & impl)
        : BpInterface<IDemoInterface>(impl)
    {

    }

    virtual uint64_t getPid() const;
    virtual uint64_t getEuid() const;
};

IMPLEMENT_META_INTERFACE(DemoInterface, MY_IFACE_NAME);

const char * IDemoInterface::MY_IFACE_NAME = "my.test.demoIface";

uint64_t BpDemoInterface::getPid() const
{
    Parcel data, reply;
    remote()->transact(DEMO_GET_PID, data, &reply);
    uint64_t pid = reply.readUint64();
    return pid;
}

uint64_t BpDemoInterface::getEuid() const
{
    Parcel data, reply;
    remote()->transact(DEMO_GET_UID, data, &reply);
    uint64_t uid = reply.readUint64();
    return uid;
}
