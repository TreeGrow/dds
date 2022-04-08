package com.luntek.chiplink.microdds;

/**
 * @author lxc
 */
public class DDS {

    // Used to load the 'b' library on application startup.
    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("fastcdr");
        System.loadLibrary("fastrtps");
    }

    /**
     * @param protocol 协议  udp4
     * @param port     端口号 32019
     * @param flag     开始/结束
     * @return
     */
    public static native long startAgent(String protocol, String port, boolean flag);
}
