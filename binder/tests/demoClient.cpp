#include <iostream>

#include <sys/types.h>
#include <unistd.h>

#include <binder/IServiceManager.h>
#include "IDemoInterface.h"

using namespace std;
using namespace android;
using namespace my_test;


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

    cout << "bye!" << endl;
}
