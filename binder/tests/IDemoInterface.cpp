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

    virtual uint64_t getPid() const {return 0;};
    virtual uint64_t getEuid() const {return 0;};
};


IMPLEMENT_META_INTERFACE(DemoInterface, MY_IFACE_NAME);

const char * IDemoInterface::MY_IFACE_NAME = "my.test.demoIface";
