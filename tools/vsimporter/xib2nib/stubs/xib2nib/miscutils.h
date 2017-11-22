
template <typename T, unsigned S>
inline unsigned arraySize(const T (&v)[S]) {
    return S;
}

#ifdef _WIN32
#ifdef __MINGW32__
#define _mkdir(x) mkdir(x)
#define strcpy_s(dest, dmax, src) strncpy(dest, src, dmax)
#endif
#else
#define _mkdir(x) mkdir(x, 0733)
#define strcpy_s(dest, dmax, src) strncpy(dest, src, dmax)
#endif

#define checkTelemetryOptIn() 0

#define getMachineID() ""

