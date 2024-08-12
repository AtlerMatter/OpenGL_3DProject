cmake_minimum_required(VERSION 3.30)

project(OpenGL_3DProject 	VERSION 0.1
				DESCRIPTION "A 3D game/simulation C++ program using OpenGL"
				LANGUAGES C CXX)


############################################################################################
#########	Linking			####################################################
############################################################################################

#Defining the files to compile and include
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.c ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/src/*.h ${CMAKE_SOURCE_DIR}/src/*.hpp)
file(GLOB_RECURSE LIB_CPP_FILES ${CMAKE_SOURCE_DIR}/lib/*.c ${CMAKE_SOURCE_DIR}/lib/*.cpp)

#Defining the libs and linking
include_directories(${CMAKE_SOURCE_DIR}/src/vendor ${CMAKE_SOURCE_DIR}/include)
link_libraries(${CMAKE_SOURCE_DIR}/lib/*.lib)


#TODO add the shader files to the solution (and maybe other files like resource files?)
#TODO put the solution file in the main dir while the files used to make the solution go to a cmake or VS folder or something


############################################################################################
#########	Targets Setup		####################################################
############################################################################################

#Adding the executable
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES} ${LIB_CPP_FILES})


############################################################################################
#########	Compiler Settings	####################################################
############################################################################################

#Setting the compiler options
if(MSVC)
	set(CMAKE_CONFIGURATION_TYPES Debug Release RelWithDebInfo)
	set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
        	"List of supported configuration types" FORCE)

	target_compile_options(${PROJECT_NAME} PRIVATE
 	   $<$<CONFIG:DEBUG>:/ZI /Ob0 /Od /RTC1 /W4 /EHsc /fp:precise /sdl /MTd>
	   $<$<CONFIG:RELEASE>:/O2 /Ob3 /EHsc /fp:precise /sdl /DNDEBUG /GL /W4 /MT>
	   $<$<CONFIG:RELWITHDEBINFO>:/O2 /Ob2 /Zi /fp:precise /DNDEBUG /W4 /MTd>
	)
#Add /MP  to all configs
else()

endif()


############################################################################################
#########	Project Structure	####################################################
############################################################################################


#Setting up active project, cwd and build/debug output folders
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/build/debug)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_SOURCE_DIR}/build/debug)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/build/release)
set_target_properties(${PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

#Putting CMAKE predefined projects inside their own folder
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#Defining misc files to include in project for ease of finding
file(GLOB_RECURSE SHADER_FILES ${CMAKE_SOURCE_DIR}/res/*.glsl)
file(GLOB_RECURSE MISC_FILES ${CMAKE_SOURCE_DIR}/res/*.*)
#list(REMOVE_ITEM ${MISC_FILES} ${SHADER_FILES})
target_sources(${PROJECT_NAME} PRIVATE ${MISC_FILES})

#Defining the folder structure for the project
source_group(TREE ${CMAKE_SOURCE_DIR}/src PREFIX "src" FILES ${SOURCE_FILES} ${HEADER_FILES})
source_group(TREE ${CMAKE_SOURCE_DIR}/lib PREFIX "lib" FILES ${LIB_CPP_FILES})
source_group(TREE ${CMAKE_SOURCE_DIR}/res PREFIX "res" FILES ${MISC_FILES})

#Disable ZERO_CHECK project
#set(CMAKE_SUPPRESS_REGENERATION true)