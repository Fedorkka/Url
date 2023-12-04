project(UrlParser)

set(HEADER_FILES
        Url.h
)

set(SOURCE_FILES
        Url.cpp
)

add_library(UrlParser_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})