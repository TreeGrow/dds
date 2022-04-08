#include <jni.h>
#include <string>
#include <uxr/agent/AgentInstance.hpp>
#include <android/log.h>
#include <uxr/agent/utils/ArgumentParser.hpp>
#include <uxr/agent/AgentInstance.hpp>
#include <uxr/agent/transport/custom/CustomAgent.hpp>
#include <uxr/agent/publisher/Publisher.hpp>

const char *LOG_TAG = "native-lib";
bool ready = true;   // 全局标志位


extern "C"
JNIEXPORT jlong JNICALL
Java_com_luntek_chiplink_microdds_DDS_startAgent(JNIEnv *env, jobject thiz,
                                                        jstring protocol,
                                                        jstring port,
                                                        jboolean flag) {
    ready = flag;
    const char *cprotocol = nullptr;
    cprotocol = env->GetStringUTFChars(protocol, nullptr);

    const char *cport = nullptr;
    cport = env->GetStringUTFChars(port, nullptr);

    const char *argv[] = {"microxrce_agent", cprotocol, "--port", cport, "-v", "6"};
    const int argc = sizeof(argv) / sizeof(argv[0]);
    auto transport_kind = eprosima::uxr::agent::TransportKind::UDP4;
    std::condition_variable exit_signal;

    std::thread agent_thread = std::thread([argc, argv, transport_kind, &exit_signal]() -> void {
        eprosima::uxr::agent::parser::ArgumentParser<eprosima::uxr::UDPv4Agent> parser(argc,
                                                                                       const_cast<char **>(argv),
                                                                                       transport_kind);

        switch (parser.parse_arguments()) {
            case eprosima::uxr::agent::parser::ParseResult::INVALID:
            case eprosima::uxr::agent::parser::ParseResult::NOT_FOUND: {
                __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "参数错误");
                break;
            }
            case eprosima::uxr::agent::parser::ParseResult::VALID: {
                // TODO: Handle serial/multiserial 'wait for device' stop
                if (parser.launch_agent()) {
                    /* Wait for user stop */
                    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, " start");
                    while (ready) {
//                        __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "running... ");
                    }
                    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, " end");
                }
                break;
            }
            case eprosima::uxr::agent::parser::ParseResult::HELP: {
                __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "显示帮助");
                break;
            }
        }

    });

    agent_thread.join();
    return static_cast<long>((long) &exit_signal);
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_luntek_chiplink_test_b_MainActivity_getAgentVersion(JNIEnv *env, jobject thiz) {
    const char *pat = eprosima::uxr::DISCOVERY_IP;
    return (env)->NewStringUTF(pat);
}


