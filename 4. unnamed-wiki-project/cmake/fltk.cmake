
# Include ExternalProject module
include(ExternalProject)
set(FLTK_SDK "${CMAKE_BINARY_DIR}/SDK/fltk")

# Configure external project
ExternalProject_Add(
	fltk
	GIT_REPOSITORY https://github.com/fltk/fltk
	CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${FLTK_SDK} -DFLTK_BUILD_EXAMPLES=OFF -DFLTK_BUILD_TEST=OFF
	UPDATE_COMMAND ""
)

# Initialization function
function(INSTALL_FLTK_FOR TARGET_NAME)
	set(LINK_DIR "${FLTK_SDK}/lib")
	file(GLOB_RECURSE LIBS CONFIGURE_DEPENDS RELATIVE ${LINK_DIR} "${LINK_DIR}/*.lib")

	target_include_directories(${TARGET_NAME} PUBLIC "${FLTK_SDK}/include")
	target_link_directories(${TARGET_NAME} PUBLIC ${LINK_DIR})
	target_link_libraries(${TARGET_NAME} PUBLIC ${LIBS})
	add_dependencies(${TARGET_NAME} fltk)
endfunction()
