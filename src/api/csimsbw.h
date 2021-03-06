#ifndef CSIMSBW_H
#define CSIMSBW_H

#include "csim/csim_export.h"

#if __cplusplus
#  define BEGIN_C_DECLS extern "C" { //
#  define END_C_DECLS   } //
#else
#  define BEGIN_C_DECLS
#  define END_C_DECLS
#endif

// C interface
BEGIN_C_DECLS;

CSIM_EXPORT int csim_loadCellml(const char* modelString);
CSIM_EXPORT int csim_reset();
CSIM_EXPORT int csim_setValue(const char* variableId, double value);
CSIM_EXPORT int csim_getVariables(char** *outArray, int *outLength);
CSIM_EXPORT int csim_getValues(double* *outArray, int *outLength);
CSIM_EXPORT int csim_steadyState();
CSIM_EXPORT int csim_simulate(
        double initialTime, double startTime, double endTime, int numSteps,
        double** *outMatrix, int* outRows, int *outCols);
CSIM_EXPORT int csim_oneStep(double step);
CSIM_EXPORT int csim_setTolerances(double aTol, double rTol, int maxSteps);
CSIM_EXPORT int csim_sayHello(char* *outString, int *outLength);
CSIM_EXPORT int csim_serialiseCellmlFromUrl(const char* url,
                                            char* *outString, int *outLength);

//! Frees a vector previously allocated by this library.
CSIM_EXPORT void csim_freeVector(void* vector);

//! Frees a matrix previously allocated by this library.
CSIM_EXPORT void csim_freeMatrix(void** matrix, int numRows);

END_C_DECLS;

#endif // CSIMSBW_H
