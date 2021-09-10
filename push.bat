adb push ./build/sync/dbus_sync_sample /usr/bin/dbus_sync_sample
adb shell chmod a+x /usr/bin/dbus_sync_sample

adb push ./build/signal/dbus_signale_sender_sample /usr/bin/dbus_signale_sender_sample
adb shell chmod a+x /usr/bin/dbus_signale_sender_sample
adb push ./build/signal/dbus_signale_recv_sample /usr/bin/dbus_signale_recv_sample
adb shell chmod a+x /usr/bin/dbus_signale_recv_sample


adb push ./build/signal/dbus_signale_sender_sample_2 /usr/bin/dbus_signale_sender_sample_2
adb shell chmod a+x /usr/bin/dbus_signale_sender_sample_2
adb push ./build/signal/dbus_signale_recv_sample_2 /usr/bin/dbus_signale_recv_sample_2
adb shell chmod a+x /usr/bin/dbus_signale_recv_sample_2

adb push ./build/signal/dbus_signale_test /usr/bin/dbus_signale_test
adb shell chmod a+x /usr/bin/dbus_signale_test

adb push ./build/method_call/dbus_method_call_listen_sample /usr/bin/dbus_method_call_listen_sample
adb shell chmod a+x /usr/bin/dbus_method_call_listen_sample
adb push ./build/method_call/dbus_method_call_req_sample /usr/bin/dbus_method_call_req_sample
adb shell chmod a+x /usr/bin/dbus_method_call_req_sample

adb shell sync
