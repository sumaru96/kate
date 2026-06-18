// create_language_directories.cpp

// This file contains the implementation of the create_directory function, 
// which is responsible for creating the directory structure for a new project based on the specified programming language (Java or Kotlin). 
// The function will create the necessary folders and files, including source code and build files, to set up a basic project structure.

#include "../main-header.hpp"
#include <iostream>
#include <filesystem>

using namespace std;

// ------------CONSTANTS-------------

    // source code for java and kotlin

const string SOURCE_KOTLIN_CODE = R"(fun main() {
    println("Hello World!")
}
)";
const string SOURCE_JAVA_CODE = R"(public class Main {
    public static void main(String[] args) {
        System.out.println("Hello World!");
    }
}
)";

    // source code for Gradle build files

const string SOURCE_KOTLIN_GRADLE_BUILD = R"(plugins {
    kotlin("jvm") version "1.9.0"
    application
}
repositories {
    mavenCentral()
}
dependencies {
}
application {
    mainClass.set("MainKt")
}
tasks.jar {
    manifest {
        attributes["Main-Class"] = application.mainClass.get()
    }
}
)";

const string SOURCE_JAVA_GRADLE_BUILD = R"(plugins {
    id 'java'
    id 'application'
}
repositories {
    mavenCentral()
}
dependencies {
}
application {
    mainClass = 'Main'
}
jar {
    manifest {
        attributes(
            'Main-Class': application.mainClass
        )
    }
}
)";



// ------------MAIN-FUNCTION-------------

    // function creation directories and files

int create_directory(const filesystem::path& path, const string& lang){

        // main path for directories and files

    filesystem::path source_directories_path;
    filesystem::path source_main_file_path;
    filesystem::path gradle_build_file_path;
    filesystem::path gradle_settings_file_path;

    // source code for Gradle settings files

    const string SOURCE_SETTINGS = "rootProject.name = \"" + path.string() + "\"";

    if (lang == "java"){

            // Here set value for java project

        source_directories_path = path / "src" / "main" / "java";
        gradle_build_file_path = path / "build.gradle";
        source_main_file_path = source_directories_path / "Main.java";
        gradle_settings_file_path = path / "settings.gradle";

            // creating dir and files for java project
        if (!is_not_error(create_project_file(source_directories_path, gradle_build_file_path,
                       SOURCE_JAVA_GRADLE_BUILD,source_main_file_path,SOURCE_JAVA_CODE,
                       gradle_settings_file_path,SOURCE_SETTINGS))) return -1;
    }else if (lang == "kotlin") {

            // Here set value for kotlin project

        source_directories_path = path / "src" / "main" / "kotlin";
        gradle_build_file_path = path / "build.gradle.kts";
        source_main_file_path = source_directories_path / "Main.kt";
        gradle_settings_file_path = path / "settings.gradle.kts";

            // creating dir and files for kotlin project
        if (!is_not_error(create_project_file(source_directories_path, gradle_build_file_path,
                        SOURCE_KOTLIN_GRADLE_BUILD,source_main_file_path,SOURCE_KOTLIN_CODE,
                        gradle_settings_file_path,SOURCE_SETTINGS))) return -1;
    }else return -1;
    return 0;
}
