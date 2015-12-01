#ifndef __IDEMOSERVICE_H__
#define __IDEMOSERVICE_H__

#include <sys/types.h>

#include <binder/IInterface.h>
#include <utils/Vector.h>
#include <utils/String16.h>
using namespace android;

namespace my_test {

// ----------------------------------------------------------------------

class IDemoInterface : public IInterface
{
public:
    DECLARE_META_INTERFACE(DemoInterface);

    virtual uint64_t getPid() const = 0;
    virtual uint64_t getEuid() const = 0;
//    virtual Vector<String16> listServices() = 0;


    enum {
        DEMO_GET_PID = IBinder::FIRST_CALL_TRANSACTION,
        DEMO_GET_UID,
        DEMO_LIST_SERVICES
    };
};

class BpDemoService : public BpInterface<IDemoInterface>
{

};

};


#endif
