#include <glib.h>                               // 包含glib库  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dbus/dbus-glib.h>
#include <dbus/dbus.h>
#include <unistd.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <signal.h>

static void WidebrightSegvHandler(int signum) {
    void *array[10];
    size_t size;
    char **strings;
    size_t i, j;

    signal(signum, SIG_DFL); /* 还原默认的信号处理handler */

    size = backtrace (array, 10);
    strings = (char **)backtrace_symbols (array, size);

    fprintf(stderr, "widebright received SIGSEGV! Stack trace:\n");
    for (i = 0; i < size; i++) {
        fprintf(stderr, "%d %s \n",i,strings[i]);
    }

    free (strings);
    exit(1);
}

static gboolean send_ding(DBusConnection *bus);// 定义发送消息函数的原型  
int main ()  
{  

    signal(SIGSEGV, WidebrightSegvHandler); // SIGSEGV      11       Core    Invalid memory reference
    signal(SIGABRT, WidebrightSegvHandler); // SIGABRT       6       Core    Abort signal from

    GMainLoop *loop;                             // 定义一个事件循环对象的指针  
    DBusConnection *bus;                         // 定义总线连接对象的指针  
    DBusError error;                             // 定义D-Bus错误消息对象  
    loop = g_main_loop_new(NULL, FALSE);         // 创建新事件循环对象  
    dbus_error_init (&error);                    // 将错误消息对象连接到D-Bus  
    printf("%d\n",__LINE__);                                           // 错误消息对象  
    bus = dbus_bus_get(DBUS_BUS_SESSION, &error);// 连接到总线  
    if (!bus) {                              // 判断是否连接错误  
        g_warning("连接到D-Bus失败: %s", error.message);  // 使用GLib输出错误警告信息  
        dbus_error_free(&error);              // 清除错误消息  
        return 1;  
    }  
    printf("%d\n",__LINE__);    
    dbus_connection_setup_with_g_main(bus, NULL);  // 将总线设为接收GLib事件循环  
      printf("%d\n",__LINE__);    
    g_timeout_add(1000, (GSourceFunc)send_ding, bus);   // 每隔1000ms调用一次send_ding()函数  
      printf("%d\n",__LINE__);                                            // 将总线指针作为参数  
    g_main_loop_run(loop);                   // 启动事件循环  
    return 0;  
}  
const char* test="ding";
static gboolean send_ding(DBusConnection *bus)  // 定义发送消息函数的细节  
{  

#if 1
    DBusMessage * msg;
    DBusMessageIter arg;
   //根据图，我们给出这个信号的路径（即可以指向对象），接口，以及信号名，创建一个Message
    if((msg = dbus_message_new_signal ("/com/burtonini/dbus/ding", "com.burtonini.dbus.Signal", "ding")) == NULL){
        fprintf(stderr,"Message NULL\n");
        return -1;
    }
    //给这个信号（messge）具体的内容
    dbus_message_iter_init_append (msg,&arg);
    if(!dbus_message_iter_append_basic (&arg,DBUS_TYPE_STRING,&test)){
        fprintf(stderr,"Out Of Memory!\n");
        return -1;
    }

    //步骤4: 将信号从连接中发送
    if( !dbus_connection_send (bus,msg,NULL)){
        fprintf(stderr,"Out of Memory!\n");
        return -1;
    }
    dbus_connection_flush (bus);
    printf("Signal Send\n");
    dbus_message_unref(msg);                 // 释放消息对象  
#endif
    return TRUE;  
}
