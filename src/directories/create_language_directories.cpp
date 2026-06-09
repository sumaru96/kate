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

    // source code for gradle build files

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
    if 'java'
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
    
        // source code for gradle settings files

    string SOURCE_SETTINGS;

        // main path for directories and files

    filesystem::path SOURCE_DIRECTORIES_PATH;
    filesystem::path SOURCE_MAIN_FILE_PATH;
    filesystem::path GRADLE_BUILD_FILE_PATH;
    filesystem::path GRADLE__SETTINGS_FILE_PATH;

    SOURCE_SETTINGS = "rootProject.name = \"" + path.string() + "\"";

    if (lang == "java"){

            // Here set value for java project

        SOURCE_DIRECTORIES_PATH = path / "src" / "main" / "java";
        GRADLE_BUILD_FILE_PATH = path / "build.gradle";
        SOURCE_MAIN_FILE_PATH = SOURCE_DIRECTORIES_PATH / "Main.java";
        GRADLE__SETTINGS_FILE_PATH = path / "settings.gradle";

            // creating dir and files for java project

        if(!is_not_error(create_dir(SOURCE_DIRECTORIES_PATH))) return -1;
        if(!is_not_error(create_file_and_write(GRADLE_BUILD_FILE_PATH, SOURCE_JAVA_GRADLE_BUILD))) return -1;
        if(!is_not_error(create_file_and_write(SOURCE_MAIN_FILE_PATH, SOURCE_JAVA_CODE))) return -1;
        if(!is_not_error(create_file_and_write(GRADLE__SETTINGS_FILE_PATH, SOURCE_SETTINGS))) return -1;

    }else if (lang == "kotlin") {

            // Here set value for kotlin project

        SOURCE_DIRECTORIES_PATH = path / "src" / "main" / "kotlin";
        GRADLE_BUILD_FILE_PATH = path / "build.gradle.kts";
        SOURCE_MAIN_FILE_PATH = SOURCE_DIRECTORIES_PATH / "Main.kt";
        GRADLE__SETTINGS_FILE_PATH = path / "settings.gradle.kts";

            // creating dir and files for kotlin project

        if(!is_not_error(create_dir(SOURCE_DIRECTORIES_PATH))) return -1;
        if(!is_not_error(create_file_and_write(GRADLE_BUILD_FILE_PATH, SOURCE_KOTLIN_GRADLE_BUILD))) return -1;
        if(!is_not_error(create_file_and_write(SOURCE_MAIN_FILE_PATH, SOURCE_KOTLIN_CODE))) return -1;
        if(!is_not_error(create_file_and_write(GRADLE__SETTINGS_FILE_PATH, SOURCE_SETTINGS))) return -1;
    
    }else {

        cerr << RED << "\n--------------------------------------------------------------\n" << RESET << endl ;
        cerr << RED << "\t [ERROR] Select one of the possible languages to create directories" << RESET << endl ;
        cerr << RED << "\n--------------------------------------------------------------\n" << RESET << endl ;

        return -1;
    }

    return 0;
}