#ifndef WRAPPEROSX_H
#define WRAPPEROSX_H

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////
/// \brief Return the path to the resource folder.
///
/// \return The path to the resource folder associate
/// with the main bundle or an empty string is there is no bundle.
///
////////////////////////////////////////////////////////////
const char* wrResourcePath();
    
const char* wrTemporaryDiractory();
    
void wrCreateGroupDirectory();

#ifdef __cplusplus
}
#endif

#endif
