// 
// Author: Kevin Ingles
// File: main.cpp
// Description: First attempt at OpenCL

#include <iostream>
#include <vector>
#include <string>

#define __CL_ENABLE_EXCEPTIONS
#include <CL/opencl.hpp>

template<typename...Args>
void PrintLn(Args...args)
{
    ((std::cout << std::forward<Args>(args) << ' '), ...);
    std::cout << '\n';
}

template<typename...Args>
void Print(Args...args)
{
    ((std::cout << std::forward<Args>(args) << ' '), ...);
}


int main()
{
    PrintLn("Hello OpenCL!");

    cl_int err = CL_SUCCESS;
    try
    {
        std::vector<cl::Platform> platforms;
        cl::Platform::get(&platforms);
        PrintLn("Platform number is:", platforms.size());

        std::string platform_vendor;   
        for (auto const& platform : platforms)
        {
            platform.getInfo(
                    static_cast<cl_platform_info>(CL_PLATFORM_VENDOR),
                                                  &platform_vendor);
            PrintLn("Platform is by:", platform_vendor);
        }
    } 
    catch (cl::Error err)
    {
        PrintLn("ERROR", err.what(), "(", err.err(), ")");
    }

    return EXIT_SUCCESS;
}

