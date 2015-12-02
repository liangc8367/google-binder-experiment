# google-binder-experiment

inspired by similar work from https://github.com/rong1129/android-binder-ipc

- created a minimum base on which I can test google binder driver and Binder/Interface framework.
- just quickly made the job done, without considering the quality of my changes.

1. binder driver is now installable and removeable.
2. passed build and tentative test under ubuntu14.04 with gcc/g++ 4.9.3.
3. to build the driver, please run gen_deps.sh, and make.
4. to load the driver and allow access from non-root users, sudo insmod and then chmod o+wr /dev/binder.
5. to run demo test, start svcmgr, then, run demo_service and demo_client.



