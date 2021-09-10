/*  Test for invoke method asynchronously */
#include <stdio.h>
#include <stdlib.h>
#include <dbus/dbus-glib.h>

static GMainLoop * main_loop;

/* 
下面是回调函数，收到method return消息触发函数 
*/
static void my_callback_func (DBusGProxy* proxy, DBusGProxyCall* call_id,  void *user_data)
{
    GError * error = NULL;
    gchar * string = NULL;
    /* 结束一个消息的收发，处理收到的消息，获取返回值或者error信息 */
    dbus_g_proxy_end_call (proxy,call_id,&error,G_TYPE_STRING,&string,G_TYPE_INVALID);
    if(error != NULL){
        g_print("Error in method call : %s\n", error->message);
        g_error_free(error);
    }else{
        g_print("SUCCESS,it is now %s\n",string);
    }
    g_main_loop_quit(main_loop);
}

int main( int argc , char ** argv)
{
    GError * error = NULL;
    DBusGConnection * connection;
    DBusGProxy    * proxy;
   
    g_type_init();
    main_loop = g_main_loop_new(NULL,TRUE);

    connection = dbus_g_bus_get (DBUS_BUS_SESSION, & error);
    if(connection == NULL){
        g_printerr ("Failed to open connection to bus : %s\n",
                error->message);
        g_error_free( error);
        exit( 1 );
    }

    /* Create a proxy object for the 'bus driver' named org.freedesktop.DBus */
    proxy = dbus_g_proxy_new_for_name (connection, "org.freedesktop.Notifications",  "/", DBUS_INTERFACE_INTROSPECTABLE);
    /* 异步触发，也可以带上一个超时的时间限制，使用dbus_g_proxy_call_with_timeout 。这里的参数只需带上输入的情况。第四个参数为携带到回调函数的user_data，第五个参数标识释放user_data的函数，例如g_free等*/
    dbus_g_proxy_begin_call (proxy,"Introspect",my_callback_func, NULL,NULL, G_TYPE_INVALID);
    g_main_loop_run(main_loop);
    return 0;
}