cmake_minimum_required(VERSION 3.5)



# Place binaries and libraries according to GNU standards.
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# When running locally build number not defined so set it default value of 0.
if (NOT DEFINED ENV{TRAVIS_BUILD_NUMBER})
    set(ENV{TRAVIS_BUILD_NUMBER} 0)
endif()

project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

###############################################################################
#  Executable
###############################################################################
add_subdirectory(greetings)
add_executable(helloworld_cli main.cpp)

target_link_libraries(helloworld_cli PRIVATE greetings)

set_target_properties(helloworld_cli PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)


###############################################################################
#  Testing
###############################################################################
include(cmake/googletest.cmake)
fetch_googletest(
    ${PROJECT_SOURCE_DIR}/cmake
    ${PROJECT_BINARY_DIR}/googletest
    )

enable_testing()
add_subdirectory(test)




# target_include_directories(helloworld
#     PRIVATE "${CMAKE_BINARY_DIR}"
# )
# set_target_properties(test_version PROPERTIES
#     COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
#     INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
# )

# target_link_libraries(helloworld_cli PRIVATE
#     helloworld
# )
# target_link_libraries(test_version
#     ${Boost_LIBRARIES}
#     helloworld
# )

# if (MSVC)
#     target_compile_options(helloworld_cli PRIVATE
#         /W4
#     )
#     target_compile_options(helloworld PRIVATE
#         /W4
#     )
#     target_compile_options(test_version PRIVATE
#         /W4
#     )
# else ()
#     target_compile_options(helloworld_cli PRIVATE
#         -Wall -Wextra -pedantic -Werror
    # )
    # target_compile_options(helloworld PRIVATE
    #     -Wall -Wextra -pedantic -Werror
    # )
    # target_compile_options(test_version PRIVATE
    #     -Wall -Wextra -pedantic -Werror
    # )
# endif()



# install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

# set(CPACK_GENERATOR DEB)

# set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
# set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

# set(CPACK_PACKAGE_CONTACT example@example.com)

# include(CPack)

# enable_testing()

# add_test(test_version test_version)
