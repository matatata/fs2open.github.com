# Uses a native opentrackclient library mainly intended for macOS and Linux
# so that headtracking natively works natively with native builds of opentrack.
#
# https://github.com/matatata/opentrack/tree/master/opentrackclient 
# https://matatata.github.io/MacOpentrack.html
#


if(PLATFORM_WINDOWS)
    # on windows opentrack uses trackir and freetrack protocols
elseif(PLATFORM_MAC)
    get_prebuilt_path(PREBUILT_PATH)
    # if it's included in the prebuilt libraries it should work right away, otherwise you should configure the following variable:
    # 
    set(OPENTRACK_SDK_PATH "${PREBUILT_PATH}" CACHE PATH "Directory containing opentrackclient.framework")
    
    add_library(opentrackclient INTERFACE)
    unset(OPENTRACKCLIENT_LIBRARY CACHE)
    find_library(OPENTRACKCLIENT_LIBRARY opentrackclient PATHS "${OPENTRACK_SDK_PATH}" NO_DEFAULT_PATH)
    if(OPENTRACKCLIENT_LIBRARY)
        message(STATUS "Using provided opentrackclient framework.")
        target_link_libraries(opentrackclient INTERFACE "${OPENTRACKCLIENT_LIBRARY}")
        target_include_directories(opentrackclient PRIVATE INTERFACE "${OPENTRACKCLIENT_LIBRARY}/Headers")

        add_target_copy_files("${OPENTRACKCLIENT_LIBRARY}")
    else()
        message(STATUS "opentrackclient.framework is not included in the set of prebuild libraries. Please define the directory containing it via OPENTRACK_SDK_PATH if you want to use native headtracking on macOS using MacOpentrack")
    endif()

elseif(PLATFORM_LINUX)
    # TODO
    # You'd need to build the SDK https://github.com/matatata/opentrack/tree/master/opentrackclient/README.md
    # and then use the generated .so file and the header file.
endif()
