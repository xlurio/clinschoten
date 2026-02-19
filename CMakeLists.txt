cmake_minimum_required(VERSION 3.10)

project(clinschoten VERSION 0.2.1 LANGUAGES C)

set(CLN_LOG_LEVEL 2 CACHE STRING "Logging level (0=NOT_SET, 1=DEBUG, 2=INFO, 3=WARNING, 4=ERROR, 5=CRITICAL)")
set_property(CACHE CLN_LOG_LEVEL PROPERTY STRINGS "0" "1" "2" "3" "4" "5")

add_library(clinschoten STATIC)

target_sources(clinschoten
    PRIVATE src/logger.c
)

target_compile_features(clinschoten PUBLIC c_std_99)

target_include_directories(clinschoten
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_definitions(clinschoten
    PUBLIC
        CLN_LOG_LEVEL=${CLN_LOG_LEVEL}
)

target_compile_features(clinschoten PUBLIC c_std_99)

add_library(CLN::clinschoten ALIAS clinschoten)

include(GNUInstallDirs)

install(TARGETS clinschoten
    EXPORT clinschotenTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT clinschotenTargets
    FILE clinschotenTargets.cmake
    NAMESPACE clinschoten::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/clinschoten
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/clinschotenConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/clinschotenConfig.cmake"
"include(CMakeFindDependencyMacro)
include(\"\${CMAKE_CURRENT_LIST_DIR}/clinschotenTargets.cmake\")
"
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/clinschotenConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/clinschotenConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/clinschoten
)

# Testing
option(CLN_BUILD_TESTING "Build the testing tree" ON)

if(CLN_BUILD_TESTING)
    enable_testing()

    add_executable(clinschoten_tests
        tests/test_runner.c
        tests/test_logger.c
    )
    
    target_link_libraries(clinschoten_tests
        PRIVATE
            clinschoten
    )
    
    target_include_directories(clinschoten_tests
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/external/ccauchy/include
    )
    
    add_test(NAME clinschoten_tests COMMAND clinschoten_tests)
endif()
