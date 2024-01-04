
# Include FetchContent module
include(FetchContent)

# Configure FetchContent
FetchContent_Declare(
	asio
	GIT_REPOSITORY https://github.com/chriskohlhoff/asio
	INSTALL_COMMAND ""
	UPDATE_COMMAND ""
)

FetchContent_MakeAvailable(asio)
FetchContent_GetProperties(asio)

# Initialization function
function(INSTALL_ASIO_FOR TARGET_NAME)
	target_include_directories(${TARGET_NAME} PUBLIC "${asio_SOURCE_DIR}/asio/include")
endfunction()
