if os.is("linux") then
    local getcxxflags = premake.gcc.getcxxflags;
    function premake.gcc.getcxxflags(cfg)
        local cxxflags = { Cxx11 = "-std=c++11" }
        local r = getcxxflags(cfg);
        local r2 = table.translate(cfg.flags, cxxflags);
        for _,v in ipairs(r2) do table.insert(r, v) end
        return r;
    end
    table.insert(premake.fields.flags.allowed, "Cxx11");
end

solution "gengine"
    configurations { "Debug", "Release", "DebugEmscripten", "ReleaseEmscripten" }

    platforms { "x32", "x64" }

    project "gengine"
        kind "ConsoleApp"
        language "C++"

        files {
            "../src/**.h",
            "../src/**.cpp",
            "../deps/common/libembindcefv8/src/*.*"
            }

        includedirs {
            "../src/application",
            "../src/gui",
            "../src/kernel",
            "../deps/common/libembindcefv8/src/"
            }

        links {
            "Urho3D"
            }

        flags {
            "ExtraWarnings",
            "FloatFast",
            "NoExceptions",
            "NoFramePointer",
            "NoNativeWChar"
            }

        defines { "URHO3D_SPINE" }

        if os.is("linux") then
            defines { "_LINUX" }
            flags { "Cxx11" }
            buildoptions { "-Wno-error=unused-variable -Wno-error=unused-parameter" }
            linkoptions { "-Wl,-rpath=../deps/linux/lib64/"}
        elseif os.is("windows") then
            defines { "_WINDOWS", "NOMINMAX" }
            flags { "StaticRuntime" }
        end

        configuration "Debug*"
            defines { "DEBUG" }
            flags { "Symbols" }
            targetname "gengined"

        configuration "Release*"
            defines { "NDEBUG" }
            flags { "Optimize" }
            targetname "gengine"

        configuration "*Emscripten"
            defines { "EMSCRIPTEN" }
            targetsuffix ".bc"
            if not os.is("windows") then
                linkoptions { "-Wno-warn-absolute-paths" }
            end

        configuration "not *Emscripten"
            defines { "CEF" }

            if os.is("linux") then
                includedirs {
                    "../deps/linux/include",
                    "../deps/linux/include/cef"
                    }
                links {
                    "GL",
                    "cef",
                    "cef_dll_wrapper",
                    "pthread",
                    "dl",
                    "stdc++",
                    "m"
                    }

            elseif os.is("windows") then
                includedirs { "../deps/windows/include" }
                includedirs { "../deps/windows/include/cef" }
                libdirs { "../deps/windows/lib" }
                links {
                    "OpenGL32",
                    "libcef",
                    "libcef_dll_wrapper",
                    "glew32"
                    }
            end

        local function useUrho3D(targetPlatform, targetMode)
            includedirs {
                "../deps/common/Urho3D/build/" .. targetPlatform .. "/" .. targetMode .. "/include",
                "../deps/common/Urho3D/build/" .. targetPlatform .. "/" .. targetMode .. "/include/Urho3D/ThirdParty"
            }

            libdirs {
                "../deps/common/Urho3D/build/" .. targetPlatform .. "/" .. targetMode .. "/lib"
            }
        end

        configuration { "Debug*", "not *Emscripten" }
            if os.is("linux") then
                useUrho3D("linux", "debug")
            end
        configuration { "Release*", "not *Emscripten" }
            if os.is("linux") then
                useUrho3D("linux", "release")
            end
        configuration { "Debug*", "*Emscripten" }
            useUrho3D("emscripten", "debug")
        configuration { "Release*", "*Emscripten" }
            useUrho3D("emscripten", "release")

        configuration { "not *Emscripten", "x32" }
            libdirs { "../deps/linux/lib32" }

        configuration { "not *Emscripten", "x64" }
            libdirs { "../deps/linux/lib64" }
