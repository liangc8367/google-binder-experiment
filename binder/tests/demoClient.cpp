#include <iostream>

#include <sys/types.h>
#include <unistd.h>

#include <binder/IServiceManager.h>
#include "IDemoInterface.h"

using namespace std;
using namespace android;
using namespace my_test;

// copied from servicemanager/service_manager.c
// not thread-safe, just make my test job done.
static const char *str8(const uint16_t *x, size_t x_len)
{
    static char buf[128];
    size_t max = 127;
    char *p = buf;

    if (x_len < max) {
        max = x_len;
    }

    if (x) {
        while ((max > 0) && (*x != '\0')) {
            *p++ = *x++;
            max--;
        }
    }
    *p++ = 0;
    return buf;
}


int main(int argc, char * argv[])
{
    pid_t pid = getpid();
    uid_t uid = getuid();
    cout << "demo client, pid: " << pid << ", uid: " << uid << endl;

    sp<IServiceManager> svcMgr = defaultServiceManager();
    sp<IBinder> binder = svcMgr->getService(String16(IDemoInterface::MY_IFACE_NAME));

    cout << "demo iface binder := " << binder.get() << endl;

    sp<IDemoInterface> demoIface = IDemoInterface::asInterface(binder);

    cout << "demoIface := " << demoIface.get() << endl;

    uint64_t pid2 = demoIface->getPid();

    cout << "my pid: " << pid2 << endl;

    vector<String16> services = demoIface->listServices();
    cout << "services are " << endl;
    for (const String16 &s : services) {
        const char16_t * ss = s;
        cout << str8((const uint16_t *)ss, s.size()) << endl;
    }
    cout << "." << endl;

    cout << "bye!" << endl;
}
