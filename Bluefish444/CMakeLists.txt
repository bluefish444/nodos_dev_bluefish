# Copyright MediaZ Teknoloji A.S. All Rights Reserved.

# Dependencies
# ------------
if (NOT WIN32)
    message(FATAL_ERROR "Unsupported platform: Currently, only Windows implementation is included")
endif()

nos_generate_flatbuffers("${CMAKE_CURRENT_SOURCE_DIR}/Config" "${CMAKE_CURRENT_SOURCE_DIR}/Source" "cpp" "${NOS_SDK_DIR}/types" Bluefish444_generated)


set(INCLUDE_FOLDERS "")
set(DEPENDENCIES bf444_headers Bluefish444_generated ${NOS_SYS_VULKAN_5_8_TARGET} ${NOS_PLUGIN_SDK_TARGET})

nos_add_plugin("Bluefish444" "Bluefish444_generated;${NOS_SYS_VULKAN_5_8_TARGET};${NOS_PLUGIN_SDK_TARGET}" "${INCLUDE_FOLDERS}")
nos_group_targets("Bluefish444;Bluefish444_generated" "Bluefish Plugins")




