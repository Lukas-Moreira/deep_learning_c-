cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

option(FUNC_TST "Activations tests" OFF)
option(IMP_TST "Functions Implementations" OFF)
option(BM "Activation BENCHMARK Compilation" OFF)

if(FUNC_TST)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()
    include(GoogleTest)

    # Pasta onde os executáveis de teste serão colocados
    set(TESTS_OUTPUT_DIR "${CMAKE_BINARY_DIR}/tests")
    file(MAKE_DIRECTORY "${TESTS_OUTPUT_DIR}")

    # 1) pega todos os .cpp diretamente da pasta tests/
    file(GLOB TEST_FILES CONFIGURE_DEPENDS
        "${PROJECT_SOURCE_DIR}/tests/*.cpp"
    )

    # 2) se você tiver "código de produção" em src/, liste aqui (ou transforme em library)
    file(GLOB_RECURSE APP_SRC_FILES CONFIGURE_DEPENDS
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
    )

    foreach(test_file ${TEST_FILES})
        # nome do executável = nome do arquivo sem extensão
        get_filename_component(test_name "${test_file}" NAME_WE)

        add_executable("${test_name}"
            "${test_file}"
            ${APP_SRC_FILES}
        )

        target_include_directories("${test_name}" PRIVATE
            "${PROJECT_SOURCE_DIR}/include"
            "${PROJECT_SOURCE_DIR}/headers"   # se você usa ../headers/ no código
        )

        target_compile_options("${test_name}" PRIVATE
            -Wall -Wextra -pedantic
            -Wno-enum-compare
            -Wno-maybe-uninitialized
            -Wno-uninitialized
            -Wno-unused-parameter
        )

        target_link_libraries("${test_name}" PRIVATE
            GTest::gtest_main
        )

        # executável vai para build/tests/<test_name>
        set_target_properties("${test_name}" PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${TESTS_OUTPUT_DIR}"
        )

        gtest_discover_tests("${test_name}")
    endforeach()
endif()


# if(IMP_TST)
#     set(PROJECT_FUNCS "MiddleFunctions")
#     include(FetchContent)
#     FetchContent_Declare(
#         googletest
#         URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#     )
#     # For Windows: Prevent overriding the parent project's compiler/linker settings
#     set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#     FetchContent_MakeAvailable(googletest)

#     enable_testing()
#     set(PROJECT_TEST_IMPLT test_${PROJECT_FUNCS}) 
    
#     file(GLOB_RECURSE TEST_SRC_FILES "${PROJECT_SOURCE_DIR}/tests/middle.cpp" "${PROJECT_SOURCE_DIR}/src/utils.cpp") 
    
#     add_executable(${PROJECT_TEST_IMPLT} ${TEST_SRC_FILES}) 
    
#     target_compile_options(
#         ${PROJECT_TEST_IMPLT} PRIVATE 
#         -Wall 
#         -Wextra 
#         -pedantic 
#         -Wno-enum-compare 
#         -Wno-maybe-uninitialized 
#         -Wno-uninitialized 
#         -Wno-unused-parameter
#     ) 
    
#     target_link_libraries(
#         ${PROJECT_TEST_IMPLT} 
#         GTest::gtest_main
#     ) 
    
#     include(GoogleTest) 
    
#     gtest_discover_tests(${PROJECT_TEST_IMPLT}) 
# endif()

if(BM)
    find_package(benchmark REQUIRED)
    set(MiddleFunctions "MiddleFunctions")
    set(PROJECT_BENCHMARK "Benchmark_${MiddleFunctions}")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/benchmarks)
    file(GLOB_RECURSE BENCHMARK_SRC_FILES "${PROJECT_SOURCE_DIR}/benchmark/*.cpp" "${PROJECT_SOURCE_DIR}/src/utils.cpp" "../src/myfunctions.cpp")

    add_executable(${PROJECT_BENCHMARK} ${BENCHMARK_SRC_FILES})

    target_compile_options(
        ${PROJECT_BENCHMARK} PRIVATE 
        -Wall 
        -Wextra 
        -pedantic 
        -Wno-enum-compare 
        -Wno-maybe-uninitialized 
        -Wno-uninitialized 
        -Wno-unused-parameter
    )


    target_link_libraries(
        ${PROJECT_BENCHMARK} 
        PRIVATE
        benchmark::benchmark 
    )

endif(BENCHMARK)
