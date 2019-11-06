#ifndef GAMELIB_GLOBAL_HH
#define GAMELIB_GLOBAL_HH

#include <QtCore/qglobal.h>

#if defined(GAMELIB_LIBRARY)
#  define GAMELIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define GAMELIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GAMELIB_GLOBAL_HH
