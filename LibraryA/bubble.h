#if defined(_WIN32)
#if defined(EXPORTING_MYMATH)
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC __declspec(dllimport)
#endif
#else  // non windows
#define DECLSPEC
#endif

#ifdef __cplusplus
extern "C" {
#endif

void DECLSPEC sort_bubble(int arr[], int len);

#ifdef __cplusplus
}
#endif